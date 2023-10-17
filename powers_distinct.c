/


/* Includes */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>


#define MAX     100

/* Generate a linked list capable of storing mpz_t sized integers */
typedef struct node node;
struct node {
        mpz_t value;
        struct node* next;
};


void clear_mpz_nodes(struct node* head);
int main(int argc, char** argv);
int isDistinct(mpz_t power, struct node* head);
void push(struct node* current, mpz_t val);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        /* Define our HEAD for linked list */
        struct node* head = NULL;
        head = malloc(sizeof(node));

        mpz_t power;
        mpz_init(power);

        uint64_t count = 0;

        uint64_t a, b;

        for(a = 2; a <= MAX; a++){
                for(b = 2; b <= MAX; b++){

                        mpz_ui_pow_ui(power, a, b);
                        count += isDistinct(power, head);
                }
        }

        printf("%"PRIu64"\n", count);

        /* Release resources associated with our heap structure allocations and
         * also the resources initialised when mpz_* types are defined */
        clear_mpz_nodes(head);

        return 0;
}


/* Iterates over the linked list; if
 * the power is in the list, breaks and
 * returns false otherwise appending */
int isDistinct(mpz_t power, struct node* head)
{
        struct node* current = head;

        for( ; current->next != NULL; current = current->next){

                /* mpz_cmp returns 0 if they are equal
                 * most correct to check equality with 0
                 * as it also returns other ints */
                if(!mpz_cmp(current->value, power)){
                        return 0;
                }

        }

        push(current, power);

        return 1;
}


/* Here we push the value into a new node on
 * the end in the assumption that: 1) It has
 * already been totally iterated over; and 2)
 * All duplicate values have been caught */
void push(struct node* current, mpz_t val)
{
	/* Now we can add a new variable */
	current->next = malloc(sizeof(node));
        mpz_init(current->next->value);
	mpz_set(current->next->value, val);

	current->next->next = NULL;
}


/* Free the resources associated with this structure and the mpz_* type */
void clear_mpz_nodes(struct node* head)
{
        /* The double reference means that we need not fuss about checking if
         * this is NULL or not on entry */
        node** curr = &head;
        struct node* tmp = NULL;

        while(*curr){

                tmp = *curr;
                mpz_clear(tmp->value);
                *curr = ((*curr)->next);

                free(tmp);
        }

        return;

}

