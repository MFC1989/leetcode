
//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>
//
//#ifdef _DEBUG
//#ifndef DBG_NEW
//#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//#define new DBG_NEW
//#endif
//#endif  // _DEBUG


#include <iostream>
#include <climits>
#include <stack>
#include <list>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

 struct ListNode 
 {
	 int val;
	 struct ListNode *next;

	 ListNode(int v)
	 {
		 this->val = v;
		 this->next = NULL;
	 }
	 ListNode()
	 {
		 this->val = 0;
		 this->next = NULL;
	 }
 };


 void InitList(ListNode * head)
 {
	 head = new ListNode();
 }

 void pushTail(ListNode * head)
 {
	 ListNode * h = head;
	 int tmp;
	 
	 while (cin>>tmp&&tmp!=-1)
	 {
		 ListNode * p = new ListNode(tmp);
	
		 h->next = p;				//尾插法    --尾插法的特征是每次在尾部插入 
		 h = p;
		 //p->next = h->next;			//头插法    --头插法的特征是头部不变
		 //h->next = p;
	 }
 }


 //leetcode 82
 struct ListNode* removeElements(struct ListNode* head, int val)
 {
	 struct ListNode **h, *p;

	 h = &head;
	 int count = 0;
	 while (*h) 
	 {
		 p = *h;
		 if ((*h)->val == val) 
		 {
			
			 *h = p->next;
			 free(p);
		 }
		 else
		 {
			 h = &p->next;
		 }
	 }

	 return head;
 }


 //leetcode 83
 struct ListNode* deleteDuplicates(struct ListNode* head)
 {
	 struct ListNode * h = head->next;
	 struct ListNode * r;
	 while (h->next!=NULL)
	 {
		 if (h->val == h->next->val)
		 {
			 r = h->next;
			 h->next = h->next->next;
			 delete(r);
		 }
		 else
		 {
			 h = h->next;
		 }
	 }
	 
	 return head;
 }
 

#define MIN(x,y) (((x)<(y))?(x):(y))

 //
 struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	 
	 if (!l1&&!l2)
	 {
		 return NULL;
	 }
	
	 if (l1&&!l2)
	 {
		 return l1;
	 }
	 if (!l1&&l2)
	 {
		 return l2;
	 }
	 struct ListNode * head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	 struct ListNode * h = head1;
	 h->next = NULL;

	 struct ListNode * r = NULL;
	 bool isFirst = false;
	 bool isLs1 = false;

	 while (l1  && l2)
	 {
		 if (l1->val < l2->val)
		 {
			 isLs1 = true;
		 }
		 else
		 {
			 isLs1 = false;
		 }

		 if (!isFirst)
		 {
			 h->val = MIN(l1->val, l2->val);
			 h->next = NULL;
			 isFirst = true;
		 }
		 else
		 {
			 struct ListNode * x = (struct ListNode *)malloc(sizeof(struct ListNode));
			 x->val = MIN(l1->val, l2->val);
			 h->next = x;
			 h = x;
		 }

		 if (!l1 || !l2)
		 {
			 break;
		 }

		 if (isLs1)
		 {
			 l1 = l1->next;
		 }
		 else
		 {
			 l2 = l2->next;
		 }
	 }


	 struct ListNode * cur;
	 if (l1)
	 {
		 cur = l1;
	 }
	 else
	 {
		 cur = l2;
	 }

	 while (cur)
	 {
		 struct  ListNode * z = (struct ListNode *)malloc(sizeof(struct ListNode));
		 z->val = cur->val;
		 z->next = NULL;

		 h->next = z;
		 h = z;
		 cur = cur->next;
	 }

	 return head1;
 }


 //回文链表
 typedef struct ListNode* pNODE;
 bool isPalindrome(struct ListNode* head) 
 {
	 pNODE h = head;
	 pNODE fast=head;
	 pNODE slow=head;

	 stack<int> mStack;

	 int totalLen = 1;
	 while (h)
	 {
		 if (fast->next)
		 {
			 totalLen++;
			 fast = fast->next;
		 }
		 else
		 {
			 break;
		 }

		 if (fast->next)
		 {
			 fast = fast->next;
			 totalLen++;
		 }
		 else
		 {
			 break;
		 }

		 slow = slow->next;
		 
	 }

	 if (totalLen%2==0)			
	 {
		 slow = slow->next;
	 }

	 while (slow)
	 {
		 mStack.push(slow->val);
		 if (slow->next)
		 {
			 slow = slow->next;
		 }
		 else
		 {
			 break;
		 }
	 }

	 while (!mStack.empty())
	 {
		 int tmp = mStack.top();
		 if (head->val!=tmp)
		 {
			 return false;
		 }
		 mStack.pop();
		 head = head->next;
	 }

	 return true;
 }


 //leetcode 206
 struct ListNode* reverseList(struct ListNode* head)
 {



	 return head;
 }




int main()
{	
	

	//_CrtDumpMemoryLeaks();
	return 0;
}