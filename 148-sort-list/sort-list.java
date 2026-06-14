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
    public ListNode mid(ListNode head){
        if(head==null || head.next==null) return head;
        ListNode slow=head,fast=head,prev=null;
        while(fast!=null && fast.next!=null){
            prev=slow;
            slow=slow.next;
            fast=fast.next.next;
        }
        if(prev!=null){
            prev.next=null;
        }
        return slow;
    }
   ListNode marge(ListNode a,ListNode b){
        ListNode temp=new ListNode(0);
        ListNode dummy=temp;
        while(a!=null && b!=null){
            if(a.val<b.val){
                temp.next=a;
                a=a.next;
            }
            else{
                temp.next=b;
                b=b.next;
            }
            temp=temp.next;
        }
        if(a!=null)temp.next=a;
        if(b!=null)temp.next=b;
        return dummy.next;
   }
    public ListNode sortList(ListNode head) {
        if(head==null ||head.next==null) return head;
        ListNode h1=head;
        ListNode h2=mid(head);
        ListNode l=sortList(h1);
        ListNode r=sortList(h2);
        return marge(l,r);
    }
}