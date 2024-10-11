#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain& rhs);
        Brain& operator=(const Brain& rhs);
        ~Brain();

    //setter and getters method
        void setIdeas(int i, const std::string& setIdea);
        std::string getIdeas(int i) const;

};

#endif