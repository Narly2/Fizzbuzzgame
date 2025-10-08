#pragma once

#include <string>


class Players
{
    public:

        Players(const std::string& playerName);
        std::string getName() const;

        ~Players();

    protected:

    private:
        std::string name;
};

