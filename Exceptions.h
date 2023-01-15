
#ifndef PLAYER_CPP_EXCEPTIONS_H
#define PLAYER_CPP_EXCEPTIONS_H

#include "utilities.h"

class DeckFileNotFound: public std::exception{
public:
    DeckFileNotFound() = default;
    DeckFileNotFound(const DeckFileNotFound&) = default;
    DeckFileNotFound& operator=(const DeckFileNotFound&) = default;
    ~DeckFileNotFound() = default;

    const char* what() const noexcept override;
};

class DeckFileFormatError: public std::exception{
    int m_line;
public:
    DeckFileFormatError(const int line):
    m_line(line)
    {}
    DeckFileFormatError(const DeckFileFormatError&) = default;
    DeckFileFormatError& operator=(const DeckFileFormatError&) = default;
    ~DeckFileFormatError() = default;

    const char* what() const noexcept override;
};

class DeckFileInvalidSize: public std::exception{
public:
    DeckFileInvalidSize() = default;
    DeckFileInvalidSize(const DeckFileInvalidSize&) = default;
    DeckFileInvalidSize& operator=(const DeckFileInvalidSize&) = default;
    ~DeckFileInvalidSize() =default;

    const char* what() const noexcept override;
};

/***********************************************************************************************************************
 *                              Implementation of what() in all subclasses
 **********************************************************************************************************************/

const char* DeckFileNotFound::what() const noexcept
{
    return "Deck File Error: File not found";
}

const char* DeckFileFormatError::what() const noexcept
{
    std::string message = "Deck File Error: File format error in line ";
    message += std::to_string(m_line);
    return message.c_str();
}

const char* DeckFileInvalidSize::what() const noexcept
{
    return "Deck File Error: Deck size is invalid";
}

#endif //PLAYER_CPP_EXCEPTIONS_H
