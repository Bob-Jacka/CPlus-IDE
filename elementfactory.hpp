#ifndef ELEMENTFACTORY_HPP
#define ELEMENTFACTORY_HPP

class ElementFactory
{
private:
    //
public:
    ElementFactory();
    ~ElementFactory();

    void create_button() const;
    void create_label() const;
};

#endif // ELEMENTFACTORY_HPP
