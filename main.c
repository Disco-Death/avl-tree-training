#include <stdio.h>
#include <malloc.h>

int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

typedef struct {
    int key;
    int left_num;
    int right_num;
    int height;
} node_t;

void fill_in_node(node_t* node, int key, int left_num, int right_num) {
    node->key = key;
    node->num = num;
    node->left_num = left_num;
    node->right_num = right_num;
    node->height = 1;
}

typedef struct {
    node_t* array;
    int capacity;
    int size;
} avl_tree_t;

avl_tree_t* new_avl_tree(int capacity) {
    avl_tree_t* new_avl_tree = (avl_tree_t*)malloc(sizeof(avl_tree_t));
    new_avl_tree->size = 0;
    new_avl_tree->capacity = capacity;
    new_avl_tree->array = (node_t*)malloc(capacity * sizeof(node_t));
    return new_avl_tree;
}

void delete_avl_tree(avl_tree_t* tree) {
    free(tree->array);
    free(tree);
}

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

int node_height(avl_tree_t tree, int index) {
    return index < tree->size ? tree->array[index]->height : 0;
}

int bfactor(avl_tree_t* tree, int index) {
    return node_height(tree, right(index)) - node_height(tree, left(index));
}

void fix_height(avl_tree_t* tree, int index) {
    int left_height = node_height(tree, left(index));
    int right_height = node_height(tree, right(index));
    tree->array[index]->height = 1 + max(left_height, right_height);
}

int right_rotate(avl_tree_t* tree, int index) {
    node_t* tmp = tree->array[left(index)];
    tree->array[left(index)] = tree->array[right(index)];
    tree->array[right(index)] = tree->array[index];
    tree->array[index] = tmp;
    fix_height(tree, index);
    fix_height(tree, );
    return tmp;
}

node_t* left_rotate(node_t* node) {
    node_t* tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    fix_height(node);
    fix_height(tmp);
    return tmp;
}

node_t* balance(node_t* node) {
    fix_height(node);
    if (bfactor(node) == 2) {
        if (bfactor(node->right) < 0) {
            node->right = right_rotate(node->right);
        }
        return left_rotate(node);
    }
    if (bfactor(node) == -2) {
        if (bfactor(node->left) > 0) {
            node->left = left_rotate((node->left));
        }
        return right_rotate(node);
    }
    return node;
}

avl_tree_t* new_avl_tree() {
    avl_tree_t* new_avl_tree = (avl_tree_t*)malloc(sizeof(avl_tree_t));
    new_avl_tree->root = NULL;
    return new_avl_tree;
}

void delete_avl_tree(avl_tree_t* tree) {
    if (!tree) return;
    delete_node(tree->root);
    free(tree);
}

void parting_avl_tree(avl_tree_t* tree, int key, int num, int left_num, int right_num) {
    if (!num) tree->array[0] = new_node(key, left_num, right_num);
    else {
        for (int i = 0; i < array->size; i++) {
            if (array[i]->left_num == num) {
                tree->array[left(i)]
            }
            if (array[i]->right_num == num) {
                
            }
        }
    }
}

node_t* insert_to_node(node_t* node, int key, int num, int left_num, int right_num) {
    if (!node) return new_node(key, num, left_num, right_num);
    if (key < node->key) {
        node->left = insert_to_node(node->left, key, num, left_num, right_num);
    } else {
        node->right = insert_to_node(node->right, key, num, left_num, right_num);
    }
    return balance(node);
}

void fix_height_for_parted_node(node_t* node) {
    if (node->left) {
        fix_height_for_parted_node(node->left);
    }
    if (node->right) {
        fix_height_for_parted_node(node->right);
    }
    fix_height(node);
}

void fix_height_for_parted_avl_tree(avl_tree_t* tree) {
    if (!tree || !tree->root) return;
    fix_height_for_parted_node(tree->root);
}

void insert_to_avl_tree(avl_tree_t* tree, int key) {
    
    
}

void calc_avl_tree(avl_tree_t* tree) {
    if (!avl_tree_t->size) return;
    int num = 0;
    for (int i = tree->size - 1; i >= 0; i--) {
        num++;
        tree[i]->num = num;
    }
}

void fprint_avl_tree(FILE* file_w, avl_tree_t* tree) {
    for (int i = 0; i < tree->size; i++) {
        fprint_node(file_w, );
        fprintf(file_w, "%d %d %d\n",
            avl_tree_t[i]->key,
            avl_tree_t[i]->left_num,
            avl_tree_t[i]->right_num);
    }
}

int main()
{
    FILE* file_r = fopen("addition.in", "r");
    FILE* file_w = fopen("addition.out", "w");

    avl_tree_t* tree = new_avl_tree();

    int n, key, left_num, right_num;
    fscanf(file_r, "%d", &n);

    for (int i = 1; i <= n; i++) {
        fscanf(file_r, "%d %d %d", &key, &left_num, &right_num);
        parting_avl_tree(tree, key, i, left_num, right_num);
    }
    fix_height_for_parted_avl_tree(tree);

    fscanf(file_r, "%d", &key);
    insert_to_avl_tree(tree, key, n + 1, 0, 0);

    calc_avl_tree(tree);

    fprintf(file_w, "%d\n", n + 1);
    fprint_avl_tree(file_w, tree);

    delete_avl_tree(tree);

    fclose(file_w);
    fclose(file_r);
    return 0;
}