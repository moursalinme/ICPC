
template <typename A, typename B>
    ostream& operator << (ostream& os, const map<A, B> mp) {
        auto it = mp.begin();
    
        while (it != mp.end()) {
            os << '('  << it->first << ", " << it->second << ')' << endl;
            it++;
        }
        return os;
    }

template <typename A> 
    ostream& operator << (ostream& os, const vector<A> &v) { 
        int sz = min(100, (int)v.size()); 
        os << "{"; 
        for (int i = 0; i < sz; ++i) {
            if (i) os << ", ";
            os << v[i];
        }
        os << "}"; 
        return os;
    }

template <typename A, typename B> 
    ostream& operator << (ostream& os, const pair<A, B> &p) { 
        os << "(" << p.first << ", " << p.second << ")";  
        return os;
    }

template <class T> 
    ostream& operator << (ostream& os, set<T> ms) {
        auto it = ms.begin();

        for (int i = 0; it != ms.end(); ++it) {
            if (i) os << ", ";
            os << *it;
        }
        return os;
    }

    #define itrt istream_iterator<string>
    #define out(_...) {string _N = #_; replace (_N.begin(), _N.end(), ',', ' '); stringstream ss(_N); itrt it(ss);debug(it, _);}

    inline void debug(itrt it) { 
        cerr << endl;
    }

template <typename T, typename... X>
    inline void debug(itrt it, T val, X ..._value) {
        cerr << "[" << *it << ": " << val << "] ";  debug(++it, _value...);
    }

    
