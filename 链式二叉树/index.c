# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

struct BTNode
{
	int data;
	struct BTNode * pLchild;
	struct BTNode * pRchild;
};

void PreTraverseBTree(struct BTNode * pT);
struct BTNode * CreateBTree(void);
void InTraverseBTree(struct BTNode * pT);
void PostTraverseBTree(struct BTNode * pT);

int main()
{
	struct BTNode * pT = CreateBTree();//动态链式二叉树 
	
	//PreTraverseBTree(pT);
	//InTraverseBTree(pT);
	PostTraverseBTree(pT);
	return 0;
}

void PreTraverseBTree(struct BTNode * pT)
{
	//记住理解就行了
	if(pT!=NULL)
	{
		printf("%c\n", pT->data); 
		PreTraverseBTree(pT->pLchild);
		PreTraverseBTree(pT->pRchild);
	}
}

void InTraverseBTree(struct BTNode * pT)
{
	if(pT!=NULL)
	{	
		if(NULL != pT->pLchild)
		{
			InTraverseBTree(pT->pLchild);
		}
		printf("%c\n", pT->data);
		if(NULL != pT->pRchild)
		{
			InTraverseBTree(pT->pRchild);
		}
	}
}

void PostTraverseBTree(struct BTNode * pT)
{
	if(pT!=NULL)
	{	
		if(NULL != pT->pLchild)
		{
			PostTraverseBTree(pT->pLchild);
		}
		if(NULL != pT->pRchild)
		{
			PostTraverseBTree(pT->pRchild);
		}
		printf("%c\n", pT->data);
	}
}

struct BTNode * CreateBTree(void)
{
	struct BTNode *pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode *pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode *pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode *pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode *pE = (struct BTNode *)malloc(sizeof(struct BTNode));
	
	pA -> data = 'A';
	pB -> data = 'B';
	pC -> data = 'C';
	pD -> data = 'D';
	pE -> data = 'E';
	
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;
	
	return pA;	
}
