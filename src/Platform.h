#pragma once

#include <fstream>
#include <v8.h>

#include "Config.h"


class CPlatform
{
private:
    static bool inited;
    static std::unique_ptr<v8::Platform> platform;

    const char *GetICUDataFile()
    {
        if (icu_path == "") return nullptr;

        std::ifstream ifile(icu_path);
        if (ifile) return icu_path.c_str();

        return nullptr;
    }

    std::string argv;
    std::string icu_path;
public:
    CPlatform(std::string argv0, std::string icu_path) : argv(argv0), icu_path(icu_path) {};
    ~CPlatform() {};
    void Init();
};
