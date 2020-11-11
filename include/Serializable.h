
#ifndef APP_SERIALIZABLE_H
#define APP_SERIALIZABLE_H
template <class Type>
class Serializable {
public:
    virtual std::string serialize(Type object) = 0 ;
    virtual Type deserialize(std::string stream) = 0;
};
#endif //APP_SERIALIZABLE_H
