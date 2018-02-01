#ifndef ABSTRACT_RESULT_HPP
#define ABSTRACT_RESULT_HPP

namespace Result {

struct AbstractResult {
    public:
    virtual double *get_buffer() = 0;
};

} // namespace Result;

#endif
