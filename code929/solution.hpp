#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

//class Solution {
//    struct Addr{
//        string name;
//        string local;
//        Addr(const std::string& _name, const std::string& _local) : local(_local) {
//            for (const char& c : _name) {
//                if (c == '+' || c == '.')
//                    continue;
//                name.push_back(c);
//            }
//        }
//
//        bool operator==(const Addr& rhs) {
//            return name == rhs.name && local == rhs.local;
//        }
//    };
//
//    struct Addr_hash {
//        size_t operator()(const Addr& rhs) {
//            return hash<string>()(rhs.name) ^ hash<string>()(rhs.local);
//        }
//    };
//public:
//    int numUniqueEmails(vector<string>& emails) {
//        unordered_set<Addr> hash;
//        for (string& cur : emails) {
//            int idx = cur.find_first_of ('@');
//            hash.insert(Addr(cur.substr(0, idx), cur.substr(idx + 1)));
//        }
//        return hash.size();
//    }
//};

class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_set<string> emailSet;
        for (auto &email: emails) {
            string local;
            for (char c: email) {
                if (c == '+' || c == '@') {
                    break;
                }
                if (c != '.') {
                    local += c;
                }
            }
            emailSet.emplace(local + email.substr(email.find('@')));
        }
        return emailSet.size();
    }
};