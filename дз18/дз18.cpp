#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//vector<string> read(const string& name ) {
//    vector<string> bad1;
//    ifstream file(name);
//    string word;
//
//    if (!file) {
//        cout << "Файл не знайдено!" << endl;
//        return bad1;
//    }
//
//    while (file >> word) {
//        bad1.push_back(word);
//    }
//
//    file.close();
//    return bad1;
//}
//
//string clean(const string& text, const vector<string>& bad1) {
//    istringstream file(text);
//    string word;
//    ostringstream ctext;
//    bool word1 = true;
//
//    while (file >> word) {
//        bool isbad = false;
//        for (const auto& bad1 : bad1) {
//            if (word == bad1) {
//                isbad = true;
//                break;
//            }
//        }
//
//        if (!isbad) {
//            if (!word1) {
//                ctext << " ";
//            }
//            ctext << word;
//            word1 = false;
//        }
//    }
//
//    return ctext.str();
//}

vector<pair<char, string>> Trans() {
    vector<pair<char, string>> trans = {
        {'а', "a"}, {'А', "A"},
        {'б', "b"}, {'Б', "B"},
        {'в', "v"}, {'В', "V"},
        {'г', "h"}, {'Г', "H"},
        {'ґ', "g"}, {'Ґ', "G"},
        {'д', "d"}, {'Д', "D"},
        {'е', "e"}, {'Е', "E"},
        {'є', "ie"}, {'Є', "Ye"},
        {'ж', "zh"}, {'Ж', "Zh"},
        {'з', "z"}, {'З', "Z"},
        {'и', "y"}, {'И', "Y"},
        {'і', "i"}, {'І', "I"},
        {'ї', "i"}, {'Ї', "Yi"},
        {'й', "i"}, {'Й', "Y"},
        {'к', "k"}, {'К', "K"},
        {'л', "l"}, {'Л', "L"},
        {'м', "m"}, {'М', "M"},
        {'н', "n"}, {'Н', "N"},
        {'о', "o"}, {'О', "O"},
        {'п', "p"}, {'П', "P"},
        {'р', "r"}, {'Р', "R"},
        {'с', "s"}, {'С', "S"},
        {'т', "t"}, {'Т', "T"},
        {'у', "u"}, {'У', "U"},
        {'ф', "f"}, {'Ф', "F"},
        {'х', "kh"}, {'Х', "Kh"},
        {'ц', "ts"}, {'Ц', "Ts"},
        {'ч', "ch"}, {'Ч', "Ch"},
        {'ш', "sh"}, {'Ш', "Sh"},
        {'щ', "shch"}, {'Щ', "Shch"},
        {'ю', "iu"}, {'Ю', "Yu"},
        {'я', "ia"}, {'Я', "Ya"},
        {'ь', ""}, {'Ь', ""}
    };
    return trans;
}

string lit(const string& text, const vector<pair<char, string>>& trans) {
    string result;
    for (char i : text) {
        bool found = false;
        for (const auto& pair : trans) {
            if (i == pair.first) {
                result += pair.second;
                found = true;
                break;
            }
        }
        if (!found) {
            result += i;
        }
    }
    return result;
}

int main() {

    //1
    /*string bad = "badwords.txt";

    auto bad1 = read(bad);

    ifstream file("list.txt");
    if (!file) {
        cout << "Файл не знайдено!" << endl;
        return 1;
    }

    ofstream file1("text.txt");
    if (!file) {
        cout << "Файл не знайдено!" << endl;
        return 1;
    }

    string line;
    string Line;

    while (getline(file, line)) {
        Line = clean(line, bad1);
        file1 << Line << endl;
    }

    file.close();
    file1.close();*/

    //2

    auto trans = Trans();

    ifstream file("list.txt");
    if (!file) {
        cout << "Файл не знайдено!" << endl;
        return 1;
    }

    ofstream file1("text.txt");
    if (!file) {
        cout << "Файл не знайдено!" << endl;
        return 1;
    }

    string list;

    while (getline(file, list)) {
        string Line = lit(list, trans);
        file1 << Line << endl;
    }

    return 0;
}