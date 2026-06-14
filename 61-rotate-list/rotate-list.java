/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null||k==0) return head;
        ListNode temp=head,prev=null;
       int c=0;
        while(temp!=null){
            temp=temp.next;
            c++;
        }
        k=k%c;
        if(c==1 || k==0) return head;
        c=c-k;
        temp=head;
        int i=0;
        while(i<c){
            prev=temp;
            temp=temp.next;
            i++;
        }
        prev.next=null;
        ListNode ne=temp;
        while(temp.next!=null){
            temp=temp.next;
        }
        temp.next=head;
        return ne;
    }
}