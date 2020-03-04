struct Node *MergeDescendLink(struct Node *head1, struct Node *head2)
{
    struct Node *head=NULL;
    if (head1->data < head2->data)
    {
		head = head1;
		head1 = head1->next;
    }
    else
    {
		head = head2;
		head2 = head2->next;
     }
     head->next = NULL;

    struct Node *pTemp = NULL;
    while ( head1!=NULL && head2!=NULL)
    {
        if (head1->data < head2->data)
        {
            pTemp = head1;
	    head1 = head1->next;
        }
	else
	{
            pTemp = head2;
	    head2 = head2->next;
	}
	pTemp->next = head;
	head = pTemp;
     }
     if (head1 != NULL)
     {
	  while(head1!=NULL)
	  {
             pTemp = head1;
	     head1 = head1->next;
	     pTemp->next = head;
	     head = pTemp;
	   }
    }
    if (head2 != NULL)
    {
	while(head2!=NULL)
	{
                pTemp = head2;
		head2 = head2->next;
		pTemp->next = head;
		head = pTemp;
	}
    }
    return head;
}
