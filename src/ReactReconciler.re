type reactElement;

module OpaqueFiber = {
  type t;
  [@bs.get] external key: t => Js.null(string) = "key";
};

type hostConfig(
  'instance,
  'textInstance,
  'publicInstance,
  'rootContainer,
  'hostContext,
  'instanceType,
  'props,
  'eventType,
);

[@bs.obj]
external makeHostConfigSupportingMutation:
  (
    ~supportsMutation: bool,
    ~getPublicInstance: 'instance => 'publicInstance,
    ~getRootHostContext: 'rootContainer => 'hostContext,
    ~getChildHostContext: (
                            ~parentHostContext: 'hostContext,
                            ~parentType: string,
                            'rootContainer
                          ) =>
                          'hostContext,
    ~prepareForCommit: (~containerInfo: 'rootContainer) => unit,
    ~resetAfterCommit: 'rootContainer => unit,
    ~createInstance: (
                       'instanceType,
                       'props,
                       'rootContainer,
                       'hostContext,
                       OpaqueFiber.t
                     ) =>
                     'instance,
    ~appendInitialChild: (~parentInstance: 'instance, ~child: 'instance) =>
                         unit,
    ~finalizeInitialChildren: (
                                'instance,
                                'instanceType,
                                'props,
                                'rootContainer,
                                'hostContext
                              ) =>
                              bool,
    ~prepareUpdate: (
                      'instance,
                      ~type_: string,
                      ~oldProps: 'props,
                      ~newProps: 'props,
                      'rootContainer,
                      'hostContext
                    ) =>
                    Js.nullable(array(string)),
    /* Text instances */
    ~createTextInstance: (
                           string,
                           'rootContainer,
                           'hostContext,
                           OpaqueFiber.t
                         ) =>
                         'instance,
    ~shouldSetTextContent: (~type_: string, 'props) => bool,
    /* ? */
    ~shouldDeprioritizeSubtree: (~type_: string, 'props) => bool,
    /* Scheduling */
    ~now: unit => float,
    ~cancelTimeout: Js_global.timeoutId => unit,
    ~scheduleTimeout: (unit => unit, int) => Js_global.timeoutId,
    ~noTimeout: int,
    /****/
    ~isPrimaryRenderer: bool,
    /*** Event components */
    ~mountEventComponent: 'eventComponentInstance => unit,
    ~handleEventTarget: ('eventType, 'props, 'rootContainer, OpaqueFiber.t) =>
                        bool,
    ~commitEventTarget: (
                          'eventType,
                          'props,
                          'instance,
                          ~parentInstance: 'instance
                        ) =>
                        unit,
    ~getChildHostContextForEventComponent: (
                                             ~parentHostContext: 'hostContext
                                           ) =>
                                           'hostContext,
    ~getChildHostContextForEventTarget: (
                                          ~parentHostContext: 'hostContext,
                                          ~type_: string
                                        ) =>
                                        'hostContext,
    ~getEventTargetChildElement: ('eventType, 'props) =>
                                 Js.null('eventTargetChildElement),
    /* Mutation */
    ~appendChild: (~parent: 'instance, ~child: 'instance) => unit,
    ~appendChildToContainer: ('rootContainer, 'instance) => unit,
    ~commitMount: ('instance, 'instanceType, 'props, OpaqueFiber.t) => unit,
    ~commitUpdate: (
                     'instance,
                     array(unit),
                     string,
                     ~oldProps: 'props,
                     ~newProps: 'props,
                     OpaqueFiber.t
                   ) =>
                   unit,
    ~insertBefore: (
                     ~parent: 'instance,
                     ~child: 'instance,
                     ~beforeChild: 'instance
                   ) =>
                   unit,
    ~insertInContainerBefore: (
                                'rootContainer,
                                ~child: 'instance,
                                ~beforeChild: 'instance
                              ) =>
                              unit,
    ~removeChild: (~parent: 'instance, ~child: 'instance) => unit,
    ~removeChildFromContainer: ('rootContainer, 'instance) => unit,
    ~hideInstance: 'instance => unit,
    ~unhideInstance: ('instance, 'props) => unit,
    /* Mutation: events */
    ~commitEventTarget: (
                          'eventType,
                          'props,
                          'instance,
                          ~parentInstance: 'instance
                        ) =>
                        unit,
    /* Mutation: text */
    ~commitTextUpdate: ('instance, ~oldText: string, ~newText: string) => unit,
    ~hideTextInstance: 'textInstance => unit,
    ~unhideTextInstance: ('textInstance, 'props) => unit,
    ~resetTextContent: 'instance => unit
  ) =>
  hostConfig(
    'instance,
    'textInstance,
    'publicInstance,
    'rootContainer,
    'hostContext,
    'instanceType,
    'props,
    'eventType,
  ) =
  "";

type t(
  'instance,
  'textInstance,
  'publicInstance,
  'rootContainer,
  'hostContext,
  'instanceType,
  'props,
  'eventType,
);

[@bs.module]
external make:
  hostConfig(
    'instance,
    'textInstance,
    'publicInstance,
    'rootContainer,
    'hostContext,
    'instanceType,
    'props,
    'eventType,
  ) =>
  t(
    'instance,
    'textInstance,
    'publicInstance,
    'rootContainer,
    'hostContext,
    'instanceType,
    'props,
    'eventType,
  ) =
  "react-reconciler";

type opaqueRoot;

[@bs.send]
external createContainer:
  (
    t(
      'instance,
      'textInstance,
      'publicInstance,
      'rootContainer,
      'hostContext,
      'instanceType,
      'props,
      'eventType,
    ),
    'rootContainer
  ) =>
  opaqueRoot =
  "createContainer";

type expirationTime;

[@bs.send]
external updateContainer:
  (
    t(
      'instance,
      'textInstance,
      'publicInstance,
      'rootContainer,
      'hostContext,
      'instanceType,
      'props,
      'eventType,
    ),
    ~element: reactElement,
    ~container: opaqueRoot
  ) =>
  expirationTime =
  "updateContainer";

[@bs.send]
external unbatchedUpdates:
  (
    t(
      'instance,
      'textInstance,
      'publicInstance,
      'rootContainer,
      'hostContext,
      'instanceType,
      'props,
      'eventType,
    ),
    unit => 'a
  ) =>
  'a =
  "unbatchedUpdates";

[@bs.get]
external isThisRendererActing:
  t(
    'instance,
    'textInstance,
    'publicInstance,
    'rootContainer,
    'hostContext,
    'instanceType,
    'props,
    'eventType,
  ) =>
  {. [@bs.set] "current": bool} =
  "IsThisRendererActing";

[@bs.send]
external flushPassiveEffects: t(_, _, _, _, _, _, _, _) => bool =
  "flushPassiveEffects";

[@bs.send]
external batchedUpdates: (t(_, _, _, _, _, _, _, _), 'a => 'r, 'a) => 'r =
  "batchedUpdates";
