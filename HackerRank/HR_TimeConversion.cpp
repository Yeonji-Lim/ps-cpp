string timeConversion(string s) {
    if(s[8] == 'A') {
        if(s.substr(0,2) == "12") return "00:" + s.substr(3, 5);
        else return s.substr(0, 8);
    } else {
        if(s.substr(0,2) == "12") return s.substr(0, 8);
        return to_string(stoi(s.substr(0, 2))+12) + s.substr(2, 6);
    }
}