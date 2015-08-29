//
// VGDAssert.hpp
// VGD Engine
//
// Created by Benjamin Arnold on 29 Aug 2015
//

/*! \file VGDAssert.hpp
* @brief Custom throw assertion for VGD.
*/

// Copyright (c) 2015 Softwariness.com
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification,
//  are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include <string>
#include <iostream>
#include <sstream>

#include <exception>

// https://www.softwariness.com/articles/assertions-in-cpp/
class AssertionFailureException : public std::exception {
public:
    AssertionFailureException(const char* expression, const char* file, int line, const std::string& message) :
        expression(expression), file(file), line(line), message(message) {

        std::ostringstream outputStream;

        if (!message.empty()) {
            outputStream << message << ": ";
        }

        if ((strcmp(expression, "false") == 0) || (strcmp(expression, "0") == 0)) {
            outputStream << "Unreachable code assertion";
        } else {
            outputStream << "Assertion '" << expression << "'";
        }

        outputStream << " failed in file '" << file << "' line " << line;
        report = outputStream.str();

        logError();
    }
    ~AssertionFailureException() throw() {}

    /// Helper class for formatting assertion message
    class StreamFormatter {
    public:
        operator const std::string() const {
            return m_stream.str();
        }

        template<typename T>
        StreamFormatter& operator << (const T& value) {
            m_stream << value;
            return *this;
        }
    private:
        std::ostringstream m_stream;
    };

    /// Log error before throwing
    // TODO(Ben): Handle redirecting and dumping to files.
    void logError() {
        std::cerr << report << std::endl;
    }


    /// The assertion message
    virtual const char* what() const throw() override {
        return report.c_str();
    }

    const char* expression;
    const char* file;
    int line;
    const std::string message;
    std::string report;
};

#ifdef NDEBUG
#define vgd_assert(EXPRESSION, MESSAGE) ((void)0)
#else
/// Assert that EXPRESSION evaluates to true, otherwise raise AssertionFailureException with associated MESSAGE (which may use C++ stream-style message formatting)
#define vgd_assert(EXPRESSION, MESSAGE) if(!(EXPRESSION)) { throw AssertionFailureException(#EXPRESSION, __FILE__, __LINE__, (AssertionFailureException::StreamFormatter() << MESSAGE)); }
#endif
