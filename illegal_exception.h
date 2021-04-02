//
// Created by Karim Alatrash on 2021-04-02.
//

#ifndef P3_ILLEGAL_EXCEPTION_H
#define P3_ILLEGAL_EXCEPTION_H


class illegal_exception {

public:
    const char * msg () const throw ()
    {
        return "illegal argument";
    }
};


#endif //P3_ILLEGAL_EXCEPTION_H
