#include <stdio.h>

union {
    struct {
        struct tree_node *l_child; // 8 octets (x86-64)
        struct tree_node *r_child; // 8 octets
    } children;
    unsigned long long data; // 8 octets
} tree;

int main(void) {
    // Initialisation du champ `data`
    tree.data = 0xFFFFFFFFFFFFFFFF; // Remplir avec 0xFF (tous les bits à 1)
    printf("Après initialisation de `data`:\n");
    printf("data: 0x%016llX\n", tree.data);
    printf("l_child: %p, r_child: %p\n", tree.children.l_child, tree.children.r_child);

    // Modification du champ `r_child`
    tree.children.r_child = 0; // Effacer les 8 octets supérieurs
    printf("\nAprès modification de `r_child`:\n");
    printf("data: 0x%016llX\n", tree.data);
    printf("l_child: %p, r_child: %p\n", tree.children.l_child, tree.children.r_child);

    // Modification du champ `l_child`
    tree.children.l_child = 0; // Effacer les 8 octets inférieurs
    printf("\nAprès modification de `l_child`:\n");
    printf("data: 0x%016llX\n", tree.data);
    printf("l_child: %p, r_child: %p\n", tree.children.l_child, tree.children.r_child);

    return 0;
}
