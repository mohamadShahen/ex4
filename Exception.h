
#ifndef PLAYER_CPP_EXCEPTIONS_H
#define PLAYER_CPP_EXCEPTIONS_H

#include "utilities.h"

class DeckFileNotFound: public std::exception{
private:
    std::string m_message;

public:
    DeckFileNotFound(const std::string& message):
    m_message(message)
    {}
    DeckFileNotFound(const DeckFileNotFound&) = default;
    DeckFileNotFound& operator=(const DeckFileNotFound&) = default;
    ~DeckFileNotFound() = default;

    const char* what() const noexcept override
    {
        return m_message.c_str();
    }
};

class DeckFileFormatError: public std::exception{
private:
    std::string m_message;

public:
    DeckFileFormatError(const std::string& message, const int& line):
    m_message(message)
    {
        m_message += std::to_string(line);
    }
    DeckFileFormatError(const DeckFileFormatError&) = default;
    DeckFileFormatError& operator=(const DeckFileFormatError&) = default;
    ~DeckFileFormatError() = default;

    const char* what() const noexcept override
    {
        return m_message.c_str();
    }
};

class DeckFileInvalidSize: public std::exception{
private:
    std::string m_message;

public:
    DeckFileInvalidSize(const std::string& message):
    m_message(message)
    {}
    DeckFileInvalidSize(const DeckFileInvalidSize&) = default;
    DeckFileInvalidSize& operator=(const DeckFileInvalidSize&) = default;
    ~DeckFileInvalidSize() =default;

    const char* what() const noexcept override
    {
        return m_message.c_str();
    }
};

#endif //PLAYER_CPP_EXCEPTIONS_H
