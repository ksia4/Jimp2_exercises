//
// Created by Kuba i Kasia on 11.06.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H



#include <memory>
#include <stack>
#include <vector>


namespace tree {

    template <class T>
    class Tree {
    public:
        Tree(const T &element = T()){
            value_ = element;
            child_left_ = nullptr;
            child_right_ = nullptr;
        }

        void Insert(const T &element);
        bool Find(const T &value);

        std::shared_ptr<T> Search(const T &value);
        size_t Size();
        size_t Depth();

        std::unique_ptr<Tree<T>> child_left_;
        std::unique_ptr<Tree<T>> child_right_;
        T value_;

        T Value() const{
            return value_;
        }

        Tree<T> *Root(){
            return this;
        }
    };


    template <class T>
    void Tree<T>::Insert(const T &element) {
        std::unique_ptr<Tree<T>> new_element = std::make_unique<Tree<T>>(Tree<T>(element));
        auto p = this;

        while (p != nullptr) {

            if (element < p->value_) {
                if (p->child_left_) {
                    p = p->child_left_.get();
                } else {
                    p->child_left_ = std::move(new_element);
                    break;
                }

            } else {
                if (p->child_right_) {
                    p = p->child_right_.get();
                } else {
                    p->child_right_ = std::move(new_element);
                    break;
                }
            }
        }
    }

    template<class T>
    std::shared_ptr<T> Tree<T>::Search(const T &value) {

        auto node = this;

        while (node != nullptr) {

            if (node->value_ == value) {
                return std::make_shared<T>(node->value_);
            }
            if (value < node->value_) {
                node = node->child_left_.get();
            }

            else {
                node = node->child_right_.get();
            }
        }
        return nullptr;
    }

    template<class T>
    bool Tree<T>::Find(const T &value) {
        return (Search(value) != nullptr);
    }

    template <class T>
    size_t Tree<T>::Depth() {
        size_t left=0, right=0;
        if (child_left_) left=child_left_->Depth();
        if (child_right_) right=child_right_->Depth();
        if (left > right){
            return ++left;
        }

        return ++right;
    }

    template <class T>
    size_t Tree<T>::Size() {
        size_t size = 1;

        if (child_left_) size += child_left_->Size();
        if (child_right_) size += child_right_->Size();

        return size;
    }
}


#endif //JIMP_EXERCISES_TREE_H
