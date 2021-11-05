#include <iostream>
#include <string>
#include "Fetcher.h"
#include "Interpreter.h"

using namespace std;

int main(int argc, char* argv[]) {
    curl_global_init(CURL_GLOBAL_ALL);
    string nextFilePath;
    try{
        const Fetcher fetcher {"https://www.swiftcoder.nl/cplus/"};
        Interpreter interpreter;
        nextFilePath = fetcher.fetch_file("start.txt");
        while(nextFilePath.ends_with(".txt")){
            nextFilePath = interpreter.interpret_krul_code(nextFilePath);
            if(nextFilePath.ends_with(".txt")){
                nextFilePath = fetcher.fetch_file(nextFilePath);
            }
        }
    } catch (const exception& e){
        std::cout << e.what() << std::endl;
        curl_global_cleanup();
    }
    curl_global_cleanup();

    std::cout << "Final result:" << std::endl;
    std::cout << nextFilePath << std::endl;
}
