#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc  != 3){
        cout << "Please enter 2 arguments after program name\n"
                "\t1.name of source-file and 2.name of answer-file.\n\n"
                "Example: Braces_control.exe source.c answer.txt\n";
        return 0;
    }
    ifstream Source(argv[1]);
    if(!Source){
        cout << "Can't open source-file!" << endl;
        return 1;
    }
    ofstream Answer(argv[2]);
    if(!Answer){
        cout << "Can't open answer-file!" << endl;
        Source.close();
        return 1;
    }
    cout << "Files were opened successfully!" << endl;

    char sym;
    bool logic = true;
    int braces_counter = 0;
    while(Source >> sym){
        if(sym == '{') braces_counter++;
        if(sym == '}') braces_counter--;
        if(braces_counter < 0) logic = false;
    }
    Source.close();
    cout << "Result:\n\n";

    if(!braces_counter and logic) {
        cout << "Braces is ok!";
        Answer << "Braces if ok!";
    } else{
        if(braces_counter > 0){
            cout << braces_counter << " opening braces haven't a closing pair!" << endl;
            Answer << braces_counter << " opening braces haven't a closing pair!" << endl;
        }else if (braces_counter < 0){
            cout << -braces_counter << " closing braces haven't a opening pair!" << endl;
            Answer << -braces_counter << " closing braces haven't a opening pair!" << endl;
        }
        if (!logic){
            cout << "There are illogicality of braces! \nfor instance: \"}content{\" or \"}{content}\" ";
            Answer << "There are illogicality of braces! \nfor instance: }{ ";
        }
    }
    cout << endl;
    Answer.close();
    return 0;
}