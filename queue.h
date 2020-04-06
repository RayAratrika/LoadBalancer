struct Node
{
	int load;
	struct Node *link;
};
typedef struct Node node;

struct Queue
{
	node *front, *rear;
};
typedef struct Queue queue;

node *create_node(int);
queue *create_queue();
int isEmpty(queue *);
int qlen(queue *);
void add_load(queue *, int);
void remove_load(queue *);
int queue_load(queue *);
void load_balance(int , queue *, queue *);