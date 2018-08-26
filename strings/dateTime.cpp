#include <iostream>
//#include <ctime>

using namespace std;

int main() {
    // get time now year - month - date
//    time_t t = std::time(0);
//    tm* now = std::localtime(&t);
//    cout << (now->tm_year + 1900);
//    cout << '-' << (now->tm_mon + 1);
//    cout << '-' <<  now->tm_mday;
//    cout << endl;

    // get time now - ISO8601 format
//    time_t now;
//    time(&now);
//    char buf[sizeof "2011-10-08T07:07:09Z"];
//    strftime(buf, sizeof buf, "%Y-%m-%dT%H:%M:%SZ", gmtime(&now));
//    //strftime(buf, sizeof buf, "%FT%TZ", gmtime(&now));
//    cout << buf << endl;

    // convert char* ISO8601 to year, month, date, etc
//    const char* dateStr = "2014-11-12T19:12:14.505Z";
//    int y,M,d,h,m;
//    float s;
//    sscanf(dateStr, "%d-%d-%dT%d:%d:%fZ", &y, &M, &d, &h, &m, &s);
//    cout << y << " " << M << " " << d << " " << h << " " << m << " " << s << endl;

    // convert string ISO8601 to year, month, date, etc
//    string dateStr = "2014-11-12T19:12:14.505Z";
//    int y,M,d,h,m;
//    float s;
//    sscanf(dateStr.c_str(), "%d-%d-%dT%d:%d:%fZ", &y, &M, &d, &h, &m, &s);
//    cout << y << " " << M << " " << d << " " << h << " " << m << " " << s << endl;

    //string dateStr = "2014-11-12T19:12:14.505Z";
    string dateStr = "2018-08-25T20:14:16-05:00";
    int tzh = 0, tzm = 0;
    int y,M,d,h,m;
    float s;
    if(6 < sscanf(dateStr.c_str(), "%d-%d-%dT%d:%d:%f%d:%dZ", &y, &M, &d, &h, &m, &s, &tzh, &tzm)) {
        if (tzh < 0) {
           tzm = -tzm;    // Fix the sign on minutes.
        }
    }
    cout << y << " " << M << " " << d << " " << h << " " << m << " " << s << " " << tzm << endl;

    return 0;
}
