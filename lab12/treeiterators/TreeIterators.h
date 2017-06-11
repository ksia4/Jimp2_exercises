//
// Created by Kuba i Kasia on 11.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include "../tree/Tree.h"

namespace tree {

    //Inorder sort begin

    template <class T>
    class InOrderTreeIterator {
    public:
        InOrderTreeIterator() {

        }

        InOrderTreeIterator(const Tree<T>* root) {
            AddSubtree(root);
        }

        void operator++();

        T operator*() const {
            return nodes.top()->Value();
        }

        bool operator!=(const InOrderTreeIterator& it) const;


    private:
        std::stack<const Tree<T>*> nodes;
        void AddSubtree(const Tree<T>* tree);
    };

    template <class T>
    class Treeinorder {

    public:
        Treeinorder(const Tree<T>* root){
            referen = root;
        }

        InOrderTreeIterator<T> begin() {
            return InOrderTreeIterator<T>{referen};
        }

        InOrderTreeIterator<T> end() {
            return InOrderTreeIterator<T>();
        }


    private:
        const Tree<T>* referen;
    };

    template <class T>
    Treeinorder<T> InOrder(const Tree<T>* tree) {
        return Treeinorder<T>{tree};
    }

    template <class T>
    void InOrderTreeIterator<T>::AddSubtree(const Tree<T>* tree) {
        if (tree->child_right_)
            AddSubtree(tree->child_right_.get());
        nodes.push(tree);

        if (tree->child_left_)
            AddSubtree(tree->child_left_.get());
    }

    template <class T>
    void InOrderTreeIterator<T>::operator++() {
        nodes.pop();
    }

    template <class T>
    bool InOrderTreeIterator<T>::operator!=(const InOrderTreeIterator &it) const {

        bool res = true;
        if (nodes.empty()) {
            if (it.nodes.empty())
                res = false;
        }

        else if (!it.nodes.empty())
            res = (nodes.top() != it.nodes.top());
        return res;
    }






    //preorder now!

    template <class T>
    class PreOrderTreeIterator {
    public:
        PreOrderTreeIterator() {

        }
        PreOrderTreeIterator(const Tree<T>* root) {
            nodes.push(root);
        }

        void operator++();

        T operator*() const {
            return nodes.top()->Value();
        }

        bool operator!=(const PreOrderTreeIterator&) const;


    private:
        std::stack<const Tree<T>*> nodes;
    };

    template <class T>
    class PreOrderTreeView {

    public:
        PreOrderTreeView(const Tree<T>* root) {
            ref = root;
        }

        PreOrderTreeIterator<T> begin() {
            return PreOrderTreeIterator<T>{ref};
        }
        PreOrderTreeIterator<T> end() {
            return PreOrderTreeIterator<T>();
        }


    private:
        const Tree<T>* ref;
    };

    template <class T>
    PreOrderTreeView<T> PreOrder(const Tree<T>* tree) {
        return PreOrderTreeView<T>{tree};
    }

    template <class T>
    void PreOrderTreeIterator<T>::operator++() {
        const Tree<T>* current = nodes.top();
        nodes.pop();
        if (current->child_right_)
            nodes.push(current->child_right_.get());

        if (current->child_left_)
            nodes.push(current->child_left_.get());
    }

    template <class T>
    bool PreOrderTreeIterator<T>::operator!=(const PreOrderTreeIterator &it) const {
        bool res = true;
        if (nodes.empty()) {
            if (it.nodes.empty())
                res = false;
        }

        else if (!it.nodes.empty())
            res = (nodes.top() != it.nodes.top());
        return res;
    }










    //postorder

    template <class T>
    class PostOrderTreeIterator {
    public:
        PostOrderTreeIterator() {

        }

        PostOrderTreeIterator(const Tree<T>* root) {
            AddSubtree(root);
        }
        void operator++();

        T operator*() const {
            return nodes.top()->Value();
        }
        bool operator!=(const PostOrderTreeIterator& it) const;


    private:
        std::stack<const Tree<T>*> nodes;
        void AddSubtree(const Tree<T>* tree);
    };

    template <class T>
    class PostOrderTreeView {
    public:
        PostOrderTreeView(const Tree<T>* root) : ref{root} {

        }
        PostOrderTreeIterator<T> begin() {
            return PostOrderTreeIterator<T>{ref};
        }

        PostOrderTreeIterator<T> end() {
            return PostOrderTreeIterator<T>();
        }



    private:
        const Tree<T>* ref;
    };

    template <class T>
    PostOrderTreeView<T> PostOrder(const Tree<T>* tree) {
        return PostOrderTreeView<T>{tree};
    }

    template <class T>
    void PostOrderTreeIterator<T>::operator++() {
        nodes.pop();
    }

    template <class T>
    bool PostOrderTreeIterator<T>::operator!=(const PostOrderTreeIterator<T> &it) const {

        bool res = true;
        if (nodes.empty()) {
            if (it.nodes.empty())
                res = false;
        }

        else if (!it.nodes.empty())
            res = (nodes.top() != it.nodes.top());
        return res;
    }

    template <class T>
    void PostOrderTreeIterator<T>::AddSubtree(const Tree<T> *tree) {
        nodes.push(tree);
        if (tree->child_right_)
            AddSubtree(tree->child_right_.get());
        if (tree->child_left_)
            AddSubtree(tree->child_left_.get());
    }
}

#endif //JIMP_EXERCISES_TREEITERATORS_H
