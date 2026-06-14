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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null) return head;

        int c=0;
        ListNode temp=head;
        while(temp!=null){
            temp=temp.next;
            c++;
        }
        n=c-n;
        if(n==0){
            return head.next;
        }
        temp=head;
        ListNode prev=null;
        while(n>0){
            prev=temp;
            temp=temp.next;
            n--;
        }
        if(temp!=null)prev.next=temp.next;

        return head;
    }
}