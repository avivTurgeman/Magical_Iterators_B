#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

MagicalContainer::MagicalContainer():container_(), sorted_container_(), primes_container_(){}

bool MagicalContainer::isPrime_(int num){
    if (num < 2) {
        return false;
    }

    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool MagicalContainer::compareIntPointers_(const int* a, const int* b) {
    return (*a < *b);
}

void MagicalContainer::addElement(int element){
    auto it = std::find(container_.begin(), container_.end(), element);
    
    if(it == container_.end()){
        container_.push_back(element);

        sorted_container_.push_back(&(container_.back()));
        sort(sorted_container_.begin(), sorted_container_.end(), MagicalContainer::compareIntPointers_);
        
        if(isPrime_(element)){
            sorted_container_.push_back(&(container_.back()));
        }

        if(!cross_container_.empty()){
            cross_container_.clear();
        }

        for(int i = 0; i < container_.size() / 2; ++i){
            cross_container_.push_back(&(container_[i]));
            cross_container_.push_back(&(container_[container_.size() - 1 - i]));
        }
        if(container_.size() % 2 != 0){
            cross_container_.push_back(&(container_[container_.size() / 2]));
        }

    }
}

void MagicalContainer::removeElement(int element){

    auto it = std::find(container_.begin(), container_.end(), element);
    if (it != container_.end()) {
        container_.erase(it);

        auto sortedIt = std::find(sorted_container_.begin(), sorted_container_.end(), &(*it));
        if (sortedIt != sorted_container_.end()) {
            sorted_container_.erase(sortedIt);
        }

        auto crossIt = std::find(cross_container_.begin(), cross_container_.end(), &(*it));
        if (crossIt != cross_container_.end()) {
            cross_container_.erase(crossIt);
        }

        if (isPrime_(element)) {
            auto primesIt = std::find(primes_container_.begin(), primes_container_.end(), &(*it));
            if (primesIt != primes_container_.end()) {
                primes_container_.erase(primesIt);
            }
        }
    } else {
        throw std::runtime_error("Cannot erase non-existing element");
    }
}


size_t MagicalContainer::size() const{
    return container_.size();
}

//---------AscendingIterator-------------
MagicalContainer::AscendingIterator
::AscendingIterator(MagicalContainer& container, size_t index)
:container_(container), index_(index){}

MagicalContainer::AscendingIterator
::AscendingIterator(const AscendingIterator& other)
:container_(other.container_){}

MagicalContainer::AscendingIterator& MagicalContainer
::AscendingIterator::operator=(const AscendingIterator& other){
    if(&(container_) != &(other.container_)){
        throw runtime_error("cannot assign with different containers");    
    }
    *this = other;
    return *this;
}

int& MagicalContainer::AscendingIterator::operator*() const{
    return *(container_.sorted_container_.at(index_));
}

MagicalContainer::AscendingIterator& MagicalContainer
::AscendingIterator::operator++(){
    if(index_ == container_.sorted_container_.size() - 1){
        throw runtime_error("you reach the end");
    }
    index_++;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{return index_ == other.index_;}
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{return !(*this == other);}
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{return index_ > other.index_;}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{return index_ < other.index_;}

MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: begin () const {
    return AscendingIterator(container_);
}
MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: end () const {
    return AscendingIterator(container_);
}

//---------SideCrossIterator-------------
MagicalContainer::SideCrossIterator
::SideCrossIterator(MagicalContainer& container, size_t index)
:container_(container), index_(index){}

MagicalContainer::SideCrossIterator
::SideCrossIterator(const SideCrossIterator& other)
:container_(other.container_){}

MagicalContainer::SideCrossIterator& MagicalContainer
::SideCrossIterator::operator=(const SideCrossIterator& other){
    if(&(container_) != &(other.container_)){
        throw runtime_error("cannot assign with different containers");    
    }
    *this = other;
    return *this;
}

int& MagicalContainer::SideCrossIterator::operator*() const{
    return *(container_.cross_container_.at(index_));
}

MagicalContainer::SideCrossIterator& MagicalContainer
::SideCrossIterator::operator++(){
    if(index_ == container_.sorted_container_.size() - 1){
        throw runtime_error("you reach the end");
    }
    index_++;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{return index_ == other.index_;}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{return !(*this == other);}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{return index_ > other.index_;}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{return index_ < other.index_;}

MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: begin () const {
    return SideCrossIterator(container_);
}
MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: end () const {
    return SideCrossIterator(container_);
}

//---------PrimeIterator-------------
MagicalContainer::PrimeIterator
::PrimeIterator(MagicalContainer& container, size_t index)
:container_(container), index_(index){}

MagicalContainer::PrimeIterator
::PrimeIterator(const PrimeIterator& other)
:container_(other.container_){}

MagicalContainer::PrimeIterator& MagicalContainer
::PrimeIterator::operator=(const PrimeIterator& other){
    if(&(container_) != &(other.container_)){
        throw runtime_error("cannot assign with different containers");    
    }
    *this = other;
    return *this;
}

int& MagicalContainer::PrimeIterator::operator*() const{
    return *(container_.primes_container_.at(index_));
}

MagicalContainer::PrimeIterator& MagicalContainer
::PrimeIterator::operator++(){
    if(index_ == container_.primes_container_.size() - 1){
        throw runtime_error("you reach the end");
    }
    index_++;
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{return index_ == other.index_;}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{return !(*this == other);}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{return index_ > other.index_;}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{return index_ < other.index_;}

MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: begin () const {
    return PrimeIterator(container_);
}
MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: end () const {
    return PrimeIterator(container_);
}