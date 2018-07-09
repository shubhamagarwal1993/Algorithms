#include <iostream>
#include <regex>

using namespace std;

void regexMatch() {

    // String match
    if(regex_match("subject", regex("(sub)(.*)"))) {
        cout << "string literal matched\n";
    }

    // object match
    char cstr[] = "subject";
    string s ("subject");
    regex e ("(sub)(.*)");
    if(regex_match(s,e)) {
        cout << "string object matched" << endl;
    }
    if(regex_match(s.begin(), s.end(), e )) {
        cout << "range matched" << endl;
    }

    cmatch cm;    // same as std::match_results<const char*> cm;
    regex_match(cstr,cm,e);
    cout << "string literal with " << cm.size() << " matches" << endl;

    smatch sm;    // same as std::match_results<string::const_iterator> sm;
    regex_match(s,sm,e);
    cout << "string object with " << sm.size() << " matches" << endl;

    regex_match(s.cbegin(), s.cend(), sm, e);
    cout << "range with " << sm.size() << " matches" << endl;

    // using explicit flags:
    regex_match(cstr, cm, e, regex_constants::match_default);

    cout << "the matches were: ";
    for(unsigned i=0; i<cm.size(); ++i) {
        cout << "[" << cm[i] << "] ";
    }
    cout << endl;

    return;
}

void regexSearch() {
    string s ("this subject has a submarine as a subsequence");
    smatch m;
    regex e ("\\b(sub)([^ ]*)");    // matches words beginning by "sub"

    cout << "Target sequence: " << s << endl;
    cout << "Regular expression: /\\b(sub)([^ ]*)/" << endl;
    cout << "The following matches and submatches were found:" << endl;

    while(regex_search(s,m,e)) {
        for(auto x:m) {
            cout << x << " ";
        }
        cout << endl;
        s = m.suffix().str();
    }

  return;
}

void regexReplace() {
    string s ("there is a subsequence in the string\n");
    regex e ("\\b(sub)([^ ]*)");    // matches words beginning by "sub"

    // using string/c-string (3) version:
    cout << regex_replace(s,e,"sub-$2");

    // using range/c-string (6) version:
    string result;
    regex_replace(back_inserter(result), s.begin(), s.end(), e, "$2");
    cout << result;

    // with flags:
    cout << regex_replace(s,e,"$1 and $2",regex_constants::format_no_copy);
    cout << endl;

    return;
}

int main() {

    regexMatch();
    regexSearch();
    regexReplace();
    return 0;
}

