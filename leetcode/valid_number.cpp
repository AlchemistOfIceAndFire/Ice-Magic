//
// Created by huanyan on 2021/11/18.
//

class Solution {
public:
    bool isNumber(string s) {
        enum State {
            STATE_INITIAL,
            STATE_NUMBER_SIGN,
            STATE_NUMBER,
            STATE_POINT_WITH_NUMBER,
            STATE_POINT_WITHOUT_NUMBER,
            STATE_DECIMAL,
            STATE_E,
            STATE_E_SIGN,
            STATE_E_NUMBER
        };

        enum Event {
            EVENT_SIGN,
            EVENT_NUMBER,
            EVENT_POINT,
            EVENT_E,
            EVENT_ILLEGAL
        };

        map <State, map<Event, State>> state_machines = {
                {
                        STATE_INITIAL,              {
                                                            {EVENT_SIGN,   STATE_NUMBER_SIGN},
                                                            {EVENT_NUMBER, STATE_NUMBER},
                                                            {EVENT_POINT, STATE_POINT_WITHOUT_NUMBER},
                                                    }
                },
                {
                        STATE_NUMBER_SIGN,          {
                                                            {EVENT_NUMBER, STATE_NUMBER},
                                                            {EVENT_POINT,  STATE_POINT_WITHOUT_NUMBER},
                                                    }
                },
                {
                        STATE_NUMBER,               {
                                                            {EVENT_NUMBER, STATE_NUMBER},
                                                            {EVENT_POINT,  STATE_POINT_WITH_NUMBER},
                                                            {EVENT_E,     STATE_E},
                                                    }
                },
                {
                        STATE_POINT_WITHOUT_NUMBER, {
                                                            {EVENT_NUMBER, STATE_DECIMAL},
                                                    }
                },
                {
                        STATE_POINT_WITH_NUMBER,    {
                                                            {EVENT_NUMBER, STATE_DECIMAL},
                                                            {EVENT_E,      STATE_E},
                                                    }
                },
                {
                        STATE_DECIMAL,              {
                                                            {EVENT_NUMBER, STATE_DECIMAL},
                                                            {EVENT_E,      STATE_E},
                                                    }
                },
                {
                        STATE_E,                    {
                                                            {EVENT_SIGN,   STATE_E_SIGN},
                                                            {EVENT_NUMBER, STATE_E_NUMBER}
                                                    }
                },
                {
                        STATE_E_SIGN,               {
                                                            {EVENT_NUMBER, STATE_E_NUMBER},
                                                    }
                },
                {
                        STATE_E_NUMBER,             {
                                                            {EVENT_NUMBER, STATE_E_NUMBER},
                                                    }
                }
        };

        auto state_transfer = [&](char c) {
            if (c >= '0' && c <= '9') {
                return EVENT_NUMBER;
            } else if (c == '+' || c == '-') {
                return EVENT_SIGN;
            } else if (c == '.') {
                return EVENT_POINT;
            } else if (c == 'e' || c == 'E') {
                return EVENT_E;
            } else {
                return EVENT_ILLEGAL;
            }
        };

        State state = STATE_INITIAL;
        for (int i = 0; i < s.size(); i++) {
            Event event = state_transfer(s[i]);
            if (state_machines[state].count(event) == 0) {
                return false;
            }
            state = state_machines[state][event];
        }
        return state == STATE_NUMBER || state == STATE_POINT_WITH_NUMBER || state == STATE_DECIMAL || state == STATE_E_NUMBER;
    }
};