type hostConfig(
  'instance,
  'textInstance,
  'publicInstance,
  'rootContainer,
  'hostContext,
  'instanceType,
  'props,
  'internalInstanceHandle,
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
                       'internalInstanceHandle
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
                    Js.nullable('props),
    /* Text instances */
    ~createTextInstance: (
                           string,
                           'rootContainer,
                           'hostContext,
                           'internalInstanceHandle
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
    ~handleEventTarget: (
                          'eventType,
                          'props,
                          'rootContainer,
                          'internalInstanceHandle
                        ) =>
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
    ~commitMount: (
                    'instance,
                    'instanceType,
                    'props,
                    'internalInstanceHandle
                  ) =>
                  unit,
    ~commitUpdate: (
                     'instance,
                     array(unit),
                     string,
                     ~oldProps: 'props,
                     ~newProps: 'props,
                     'internalInstanceHandle
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
    'internalInstanceHandle,
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
  'internalInstanceHandle,
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
    'internalInstanceHandle,
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
    'internalInstanceHandle,
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
      'internalInstanceHandle,
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
      'internalInstanceHandle,
      'eventType,
    ),
    ~element: React.element,
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
      'internalInstanceHandle,
      'eventType,
    ),
    unit => 'a
  ) =>
  'a =
  "unbatchedUpdates";
