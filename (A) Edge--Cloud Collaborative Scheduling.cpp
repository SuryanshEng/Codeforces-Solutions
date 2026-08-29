#include <bits/stdc++.h>
using namespace std;

enum State {
    DONE,
    READY_P_PRE,
    WAIT_P_UP,
    READY_P_PROC,
    WAIT_P_PROC,
    WAIT_P_DOWN,
    READY_P_POST,
    WAIT_P_POST,
    READY_D_PRE,
    WAIT_D_UP,
    READY_D_PROC,
    WAIT_D_PROC,
    WAIT_D_DOWN,
    READY_D_POST,
    WAIT_D_POST
};

struct Request {
    int remote = -1;
    State state = DONE;
};

struct Task {
    int server;
    string cmd;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, bytes_per_token, num_layers;
    double S, latency, bandwidth;

    if (!(cin >> K >> S >> latency >> bandwidth
              >> bytes_per_token >> num_layers))
        return 0;

    double SLO1, SLO2, tpUB, tpBase, distBase, wtp, wc;
    cin >> SLO1 >> SLO2 >> tpUB >> tpBase >> distBase >> wtp >> wc;

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int batch;
        double a, b, c, d, e, f;
        cin >> batch >> a >> b >> c >> d >> e >> f;
    }

    vector<Request> req;

    vector<bool> busy(K + 1, false);

    auto ensure = [&](int id) {
        if (id >= (int)req.size())
            req.resize(id + 1);
    };

    auto setState = [&](const vector<int>& ids, State st) {
        for (int id : ids)
            req[id].state = st;
    };

    while (true) {
        string line;

        if (!getline(cin >> ws, line))
            return 0;

        if (line == "END")
            return 0;

        string timestamp = line;

        int E;
        cin >> E;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> events(E);

        for (int i = 0; i < E; ++i)
            getline(cin, events[i]);

        for (const string& s : events) {
            stringstream ss(s);

            string type;
            ss >> type;

            if (type == "ARR") {
                int id, len;
                ss >> id >> len;

                ensure(id);

                req[id].state = READY_P_PRE;
            }

            else if (type == "FIN") {
                int id;
                ss >> id;

                ensure(id);

                req[id].state = DONE;
            }

            else if (type == "TDN") {
                string server;
                ss >> server;

                int sid;

                if (server == "E")
                    sid = 0;
                else
                    sid = stoi(server.substr(1)) + 1;

                busy[sid] = false;

                string stage, op;
                ss >> stage >> op;

                if (stage == "P") {
                    if (op == "PRE") {
                        int remote, id;
                        ss >> remote >> id;

                        req[id].state = WAIT_P_UP;
                    }

                    else if (op == "PROC") {
                        int ls, le, remote, id;
                        ss >> ls >> le >> remote >> id;

                        req[id].state = WAIT_P_DOWN;
                    }

                    else if (op == "POST") {
                        int remote, id;
                        ss >> remote >> id;

                        req[id].state = READY_D_PRE;
                    }
                }

                else {
                    int marker, m;
                    ss >> marker >> m;

                    vector<int> ids(m);

                    for (int &id : ids)
                        ss >> id;

                    if (op == "PRE") {
                        setState(ids, WAIT_D_UP);
                    }

                    else if (op == "PROC") {
                        setState(ids, WAIT_D_DOWN);
                    }

                    else if (op == "POST") {
                        setState(ids, READY_D_PRE);
                    }
                }
            }

            else if (type == "XDN") {
                string direction, stage;
                int remote, size, m;

                ss >> direction >> remote >> size >> stage >> m;

                vector<int> ids(m);

                for (int &id : ids)
                    ss >> id;

                if (stage == "PRE") {
                    if (direction == "UP")
                        setState(ids, READY_P_PROC);
                    else
                        setState(ids, READY_P_POST);
                }

                else {
                    if (direction == "UP")
                        setState(ids, READY_D_PROC);
                    else
                        setState(ids, READY_D_POST);
                }
            }
        }

        vector<Task> answer;

        auto addLocal = [&](const string& cmd) {
            if (busy[0])
                return false;

            busy[0] = true;
            answer.push_back({0, cmd});
            return true;
        };

        auto addRemote = [&](int r, const string& cmd) {
            if (busy[r + 1])
                return false;

            busy[r + 1] = true;
            answer.push_back({r + 1, cmd});
            return true;
        };

        /*
         * Local computer.
         *
         * Give priority to requests that are already close
         * to producing a token.
         */

        if (!busy[0]) {
            vector<int> ids;

            for (int i = 0; i < (int)req.size(); ++i) {
                if (req[i].state == READY_D_POST)
                    ids.push_back(i);
            }

            if (!ids.empty()) {
                string cmd =
                    "D POST -1 " + to_string(ids.size());

                for (int id : ids)
                    cmd += " " + to_string(id);

                addLocal(cmd);
                setState(ids, WAIT_D_POST);
            }
        }

        if (!busy[0]) {
            int id = -1;

            for (int i = 0; i < (int)req.size(); ++i) {
                if (req[i].state == READY_P_POST) {
                    id = i;
                    break;
                }
            }

            if (id != -1) {
                int r = req[id].remote;

                addLocal(
                    "P POST " +
                    to_string(r) + " " +
                    to_string(id)
                );

                req[id].state = WAIT_P_POST;
            }
        }

        if (!busy[0]) {
            vector<int> ids;

            for (int i = 0; i < (int)req.size(); ++i) {
                if (req[i].state == READY_D_PRE)
                    ids.push_back(i);
            }

            if (!ids.empty()) {
                string cmd =
                    "D PRE -1 " + to_string(ids.size());

                for (int id : ids)
                    cmd += " " + to_string(id);

                addLocal(cmd);
                setState(ids, WAIT_D_UP);
            }
        }

        if (!busy[0]) {
            int id = -1;

            for (int i = 0; i < (int)req.size(); ++i) {
                if (req[i].state == READY_P_PRE) {
                    id = i;
                    break;
                }
            }

            if (id != -1) {
                int best = 0;

                vector<int> load(K, 0);

                for (const auto& r : req) {
                    if (r.remote >= 0 && r.state != DONE)
                        load[r.remote]++;
                }

                for (int r = 1; r < K; ++r) {
                    if (load[r] < load[best])
                        best = r;
                }

                req[id].remote = best;
                req[id].state = WAIT_P_UP;

                addLocal(
                    "P PRE " +
                    to_string(best) + " " +
                    to_string(id)
                );
            }
        }

        /*
         * Remote computers.
         *
         * First prioritize P PROC, then D PROC.
         */

        for (int r = 0; r < K; ++r) {
            if (busy[r + 1])
                continue;

            int id = -1;

            for (int i = 0; i < (int)req.size(); ++i) {
                if (req[i].state == READY_P_PROC &&
                    req[i].remote == r) {
                    id = i;
                    break;
                }
            }

            if (id != -1) {
                req[id].state = WAIT_P_PROC;

                addRemote(
                    r,
                    "P PROC 0 " +
                    to_string(num_layers) + " " +
                    to_string(r) + " " +
                    to_string(id)
                );

                continue;
            }

            vector<int> ids;

            for (int i = 0; i < (int)req.size(); ++i) {
                if (req[i].state == READY_D_PROC &&
                    req[i].remote == r) {
                    ids.push_back(i);
                }
            }

            if (!ids.empty()) {
                string cmd =
                    "D PROC " +
                    to_string(r) + " " +
                    to_string(ids.size());

                for (int id : ids)
                    cmd += " " + to_string(id);

                addRemote(r, cmd);
                setState(ids, WAIT_D_PROC);
            }
        }

        cout << answer.size() << '\n';

        for (const auto& t : answer) {
            if (t.server == 0)
                cout << "E ";
            else
                cout << "C" << t.server - 1 << ' ';

            cout << t.cmd << '\n';
        }

        cout << flush;
    }
}