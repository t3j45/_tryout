//You are given a list of users of a social network, friends of each user, and groups the user participates in.
//
//To help users find the most interesting groups, we suggest them joining the groups where ≥50% of their friends participate.
//
//Your task is to write a program which finds a list of suggested groups for each user.
//
//INPUT SAMPLE:
//The first argument is a file that contains the information about each user, one user per line. The line is delimited by colon ‘:’ into three parts: user name, list of friends, and list of groups. The items in each part are delimited by comma ‘,’.

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <iterator>

using namespace std;

class user;

map<string, user*> userlist;

class user {
public:

    user(string &name):name_(name) {}
    ~user() {}

    void addgroup(string g) { groups_.push_back(g); }
    void addfriend(user *f) { friends_.insert(f); }

    vector<string>&       groups()  { return groups_;  }
    unordered_set<user*>& friends() { return friends_; }

    friend ostream& operator<<(ostream &out, const user* u) {
        out<<u->name_;
        return out;
    }

    void update_suggestion(string &g) {
        if (suggestions_.find(g) == suggestions_.end())
            suggestions_[g] = 1;
        else
            suggestions_[g] += 1;
    }

    void print() {
        string out_;
        out_.append(name_);
        out_.append(":");
        unsigned count = 0;
        for (map<string,unsigned>::iterator it = suggestions_.begin();
             it != suggestions_.end();
             ++it) {

            if ((find(groups_.begin(),groups_.end(),it->first) == groups_.end()) &&
                static_cast<double>(it->second) >= (static_cast<double>(friends_.size())/2)) {

                out_.append(it->first);
                out_.append(",");
                ++count;
            }
        }
        if (count) {
            cout<<out_.substr(0,out_.size()-1)<<endl;
        }
    }

private:
    string name_;
    vector<string> groups_;
    unordered_set<user*> friends_;
    map<string,unsigned> suggestions_;
};

void print() {
    for (auto it : userlist) {
        it.second->print();
    }
}

void parse(string &line) {

    stringstream ss(line);
    string buffer;

    string username;
    unordered_set<user*> friends;
    user *u;

    // Parse user name
    getline(ss,buffer,':');
    if (userlist.find(buffer) == userlist.end()) {
        u = new user(buffer);
        userlist.insert(std::pair<string,user*>(buffer,u));
    }
    else
        u = userlist[buffer];

    // Parse user friends
    getline(ss,buffer,':');
    stringstream ss1(buffer);
    while(getline(ss1,buffer,',')) {
        user *fr;
        if (userlist.find(buffer) == userlist.end()) {
            fr = new user(buffer);
            userlist.insert(std::pair<string,user*>(buffer, fr));
        }
        else
            fr = userlist[buffer];

        u->addfriend(fr);
    }

    // Parse user groups
    while (getline(ss,buffer,',')) {
        u->addgroup(buffer);
        for (auto frien : u->friends()) {
            frien->update_suggestion(buffer);
        }
    }
}


int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;

    while (getline(stream, line)) {
        parse(line);
   }
    print();
    return 0;
}
