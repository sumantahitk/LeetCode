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
     public ListNode rev(ListNode head) {
        ListNode temp=head,prev=null,next=null;
        while(temp!=null){
            next=temp.next;
            temp.next=prev;
            prev=temp;
            temp=next;
            
        }
        return prev;
    }
     public ListNode mid(ListNode head){
        if(head==null || head.next==null) return head;
        ListNode slow=head,fast=head,prev=null;
        while(fast!=null && fast.next!=null){
            prev=slow;
            slow=slow.next;
            fast=fast.next.next;
        }
        
        return slow;
    }
    public void reorderList(ListNode head) {
        ListNode mid=mid(head);
        ListNode t=mid.next;
        mid.next=null;
        ListNode h2=rev(t);
        ListNode left=head;
        ListNode ne=left;
        ListNode right=h2;
        while(right!=null){
            ListNode leftnext=left.next;
            ListNode rightnext=right.next;
            left.next=right;
            right.next=leftnext;
            left=leftnext;
            right=rightnext;
        }
       
    }
}