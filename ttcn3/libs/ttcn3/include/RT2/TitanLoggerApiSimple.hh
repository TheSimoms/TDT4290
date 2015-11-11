#ifndef TITAN_LOGGER_API_SIMPLE_HH
#define TITAN_LOGGER_API_SIMPLE_HH
namespace TitanLoggerApiSimple {


class LocationInfo_ent__type {
public:
enum enum_type { unknown = 0, controlpart = 1, testcase__ = 2, altstep__ = 3, function__ = 4, external__function = 5, template__ = 6, UNKNOWN_VALUE = 7, UNBOUND_VALUE = 8 };
};

class DefaultEnd {
public:
enum enum_type { break__ = 0, finish = 1, repeat__ = 2, UNKNOWN_VALUE = 3, UNBOUND_VALUE = 4 };
};

class ExecutorRuntime_reason {
public:
enum enum_type { connected__to__mc = 0, disconnected__from__mc = 1, initialization__of__modules__failed = 2, exit__requested__from__mc__hc = 3, exit__requested__from__mc__mtc = 4, stop__was__requested__from__mc__ignored__on__idle__mtc = 5, stop__was__requested__from__mc = 6, stop__was__requested__from__mc__ignored__on__idle__ptc = 7, executing__testcase__in__module = 8, performing__error__recovery = 9, initializing__module = 10, initialization__of__module__finished = 11, stopping__current__testcase = 12, exiting = 13, host__controller__started = 14, host__controller__finished = 15, stopping__control__part__execution = 16, stopping__test__component__execution = 17, waiting__for__ptcs__to__finish = 18, user__paused__waiting__to__resume = 19, resuming__execution = 20, terminating__execution = 21, mtc__created = 22, overload__check = 23, overload__check__fail = 24, overloaded__no__more = 25, executor__start__single__mode = 26, executor__finish__single__mode = 27, fd__limits = 28, UNKNOWN_VALUE = 29, UNBOUND_VALUE = 30 };
};

class ExecutorConfigdata_reason {
public:
enum enum_type { received__from__mc = 0, processing__failed = 1, processing__succeeded = 2, module__has__parameters = 3, using__config__file = 4, overriding__testcase__list = 5, UNKNOWN_VALUE = 6, UNBOUND_VALUE = 7 };
};

class ExecutorComponent_reason {
public:
enum enum_type { mtc__started = 0, mtc__finished = 1, ptc__started = 2, ptc__finished = 3, component__init__fail = 4, UNKNOWN_VALUE = 5, UNBOUND_VALUE = 6 };
};

class ExecutorUnqualified_reason {
public:
enum enum_type { local__address__was__set = 0, address__of__mc__was__set = 1, address__of__control__connection = 2, host__support__unix__domain__sockets = 3, UNKNOWN_VALUE = 4, UNBOUND_VALUE = 5 };
};

class RandomAction {
public:
enum enum_type { read__out = 0, seed = 1, UNKNOWN_VALUE = 2, UNBOUND_VALUE = 3 };
};

class ParallelPTC_reason {
public:
enum enum_type { init__component__start = 0, init__component__finish = 1, terminating__component = 2, component__shut__down = 3, error__idle__ptc = 4, ptc__created = 5, ptc__created__pid = 6, function__started = 7, function__stopped = 8, function__finished = 9, function__error = 10, ptc__done = 11, ptc__killed = 12, stopping__mtc = 13, ptc__stopped = 14, all__comps__stopped = 15, ptc__was__killed = 16, all__comps__killed = 17, kill__request__frm__mc = 18, mtc__finished = 19, ptc__finished = 20, starting__function = 21, UNKNOWN_VALUE = 22, UNBOUND_VALUE = 23 };
};

class ParPort_operation {
public:
enum enum_type { connect__ = 0, disconnect__ = 1, map__ = 2, unmap__ = 3, UNKNOWN_VALUE = 4, UNBOUND_VALUE = 5 };
};

class Verdict {
public:
enum enum_type { v0none = 0, v1pass = 1, v2inconc = 2, v3fail = 3, v4error = 4, UNKNOWN_VALUE = 5, UNBOUND_VALUE = 6 };
};

class Port__Queue_operation {
public:
enum enum_type { enqueue__msg = 0, enqueue__call = 1, enqueue__reply = 2, enqueue__exception = 3, extract__msg = 4, extract__op = 5, UNKNOWN_VALUE = 6, UNBOUND_VALUE = 7 };
};

class Port__State_operation {
public:
enum enum_type { started = 0, stopped = 1, halted = 2, UNKNOWN_VALUE = 3, UNBOUND_VALUE = 4 };
};

class Port__oper {
public:
enum enum_type { call__op = 0, exception__op = 1, reply__op = 2, UNKNOWN_VALUE = 3, UNBOUND_VALUE = 4 };
};

class Msg__port__recv_operation {
public:
enum enum_type { receive__op = 0, check__receive__op = 1, trigger__op = 2, UNKNOWN_VALUE = 3, UNBOUND_VALUE = 4 };
};

class Port__Misc_reason {
public:
enum enum_type { removing__unterminated__connection = 0, removing__unterminated__mapping = 1, port__was__cleared = 2, local__connection__established = 3, local__connection__terminated = 4, port__is__waiting__for__connection__tcp = 5, port__is__waiting__for__connection__unix = 6, connection__established = 7, destroying__unestablished__connection = 8, terminating__connection = 9, sending__termination__request__failed = 10, termination__request__received = 11, acknowledging__termination__request__failed = 12, sending__would__block = 13, connection__accepted = 14, connection__reset__by__peer = 15, connection__closed__by__peer = 16, port__disconnected = 17, port__was__mapped__to__system = 18, port__was__unmapped__from__system = 19, UNKNOWN_VALUE = 20, UNBOUND_VALUE = 21 };
};

class FinalVerdictType_choice_notification {
public:
enum enum_type { no__ptcs__were__created = 0, setting__final__verdict__of__the__test__case = 1, UNKNOWN_VALUE = 2, UNBOUND_VALUE = 3 };
};

class MatchingDoneType_reason {
public:
enum enum_type { done__failed__wrong__return__type = 0, done__failed__no__return = 1, any__component__done__successful = 2, any__component__done__failed = 3, all__component__done__successful = 4, any__component__killed__successful = 5, any__component__killed__failed = 6, all__component__killed__successful = 7, UNKNOWN_VALUE = 8, UNBOUND_VALUE = 9 };
};

class PortType {
public:
enum enum_type { message__ = 0, procedure__ = 1, UNKNOWN_VALUE = 2, UNBOUND_VALUE = 3 };
};

class MatchingFailureType_reason {
public:
enum enum_type { sender__does__not__match__from__clause = 0, sender__is__not__system = 1, message__does__not__match__template = 2, parameters__of__call__do__not__match__template = 3, parameters__of__reply__do__not__match__template = 4, exception__does__not__match__template = 5, not__an__exception__for__signature = 6, UNKNOWN_VALUE = 7, UNBOUND_VALUE = 8 };
};

class MatchingProblemType_reason {
public:
enum enum_type { port__not__started__and__queue__empty = 0, no__incoming__types = 1, no__incoming__signatures = 2, no__outgoing__blocking__signatures = 3, no__outgoing__blocking__signatures__that__support__exceptions = 4, component__has__no__ports = 5, UNKNOWN_VALUE = 6, UNBOUND_VALUE = 7 };
};

class MatchingProblemType_operation {
public:
enum enum_type { receive__ = 0, trigger__ = 1, getcall__ = 2, getreply__ = 3, catch__ = 4, check__ = 5, UNKNOWN_VALUE = 6, UNBOUND_VALUE = 7 };
};

class Parallel_reason {
public:
enum enum_type { creating__new__ptc = 0, function__stopped = 1, terminating__test__component__exec = 2, stopping__ptc = 3, stop__no__effect = 4, stopping__all__ptcs = 5, stop__all__no__effect = 6, killing__ptc = 7, kill__no__effect = 8, killing__all__ptcs = 9, kill__all__no__effect = 10, connecting__ports = 11, disconnecting__ports = 12, mapping__ports = 13, unmapping__ports = 14, kill__request__from__mc = 15, killing__component = 16, process__already__terminated = 17, compref__not__exist = 18, UNKNOWN_VALUE = 19, UNBOUND_VALUE = 20 };
};
} // end namespace
#endif
