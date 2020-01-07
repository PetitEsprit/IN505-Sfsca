#ifndef PART_HPP
# define PART_HPP

# include <vector>

class Part
{
    protected:
    bool marked;
    std::vector<Part*> pnearby;
public:
        const char* name;
        Part(const char *name);
        virtual ~Part() = 0;
        void addLink(Part *p);
        std::vector<Part *> &getPn();
        void mark();
        void unmark();
        bool isMarked();
        virtual void supplyFuel() = 0;
};

#endif
