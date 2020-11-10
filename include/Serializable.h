//
// Created by newton on 11/10/20.
//

#ifndef MONITOR_SERIALIZABLE_H
#define MONITOR_SERIALIZABLE_H
template <class Type>
class Serializable {
public:
    virtual std::string serialize(Type object) = 0 ;
    virtual Type deserialize(std::string stream) = 0;
};
#endif //MONITOR_SERIALIZABLE_H
