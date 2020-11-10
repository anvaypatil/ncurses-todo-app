//
// Created by newton on 11/10/20.
//

#ifndef MONITOR_SERIALIZABLE_H
#define MONITOR_SERIALIZABLE_H
template <class Type>
class Serializable {
public:
    virtual char* serialize(Type object);
    virtual Type deserialize(char* stream);
};
#endif //MONITOR_SERIALIZABLE_H
