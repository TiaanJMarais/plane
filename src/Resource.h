#ifndef RESOURCE_H
#define RESOURCE_H
#include <map>
#include <memory>
#include <set>




template <typename Resource , typename Identifier>
class ResourceHolder
{
public:
    void load(Identifier id,const std::string& filename);
    Resource&   get(Identifier id);
    const Resource&    get(Identifier id) const;
private:
    std::map<Identifier,std::unique_ptr<Resource>>mResourceMap;
};

#endif
