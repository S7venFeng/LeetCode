/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7
返回它的最小深度  2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<stdio.h>
#include<stdbool.h>

#define MAX_NODE 100000

int g_sum;

typedef struct treeQueue {
	struct TreeNode * nodeArray;
	int front;
	int rear;
	int size;
	int maxSize;
}Queue;

Queue *initQueue() {
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->nodeArray = (struct TreeNode*)malloc(sizeof(struct TreeNode)*MAX_NODE);
	q->size = 0;
	q->rear = 0;
	q->front = 0;
	q->maxSize = MAX_NODE;
	return q;
}


void insertQueue(Queue *q, struct TreeNode node) {
	if (q->rear < q->maxSize - 1) {
		q->nodeArray[q->rear] = node;
		q->rear = q->rear + 1;
		q->size++;
	}
}

void popQueue(Queue *q, struct TreeNode *node) {
	if (q->size != 0) {
		*node = q->nodeArray[q->front];
		q->front++;
		q->size--;
	}
	else {
		node = NULL;
	}
}

bool isEmpty(Queue *q) {
	if (q->size) {
		return false;
	}
	else {
		return true;
	}
}


int minDepth(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	g_sum = 0;
	Queue *q = initQueue();
	insertQueue(q, *root);
	while (false == isEmpty(q)) {
		int layers = q->size;
		g_sum++;
		while (layers) {
			struct TreeNode* node = malloc(sizeof(struct TreeNode));
			popQueue(q, node);
			if (node->left == NULL && node->right == NULL) {
				return g_sum;
			}
			if (node->left != NULL) {
				insertQueue(q, *node->left);
			}
			if (node->right != NULL) {
				insertQueue(q, *node->right);
			}
			free(node);
			layers--;
		}
	}
	return g_sum;
}