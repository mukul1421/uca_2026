import java.util.*;

public class ReverseLL {
	static class ListNode {
		int data;
		ListNode next;

		ListNode(int data) {
			this.data = data;
			this.next = null;
		}	
	}

	static ListNode reverse(ListNode head) {
	
		if(head == null || head.next == null)
			return head;

		ListNode newHead = reverse(head.next);

		head.next.next = head;
		head.next = null;

		return newHead;
	}

	static void printList(ListNode head) {
		while(head != null) {
		
			System.out.print(head.data);
			
			if(head.next != null)
				System.out.print("->");

			head = head.next;
		}
		System.out.println();
	}

	public static void main(String[] args) {
	
		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(3);
		head.next.next.next = new ListNode(4);
		
		System.out.println("Original Linked List: ");
		printList(head);

		head = reverse(head);
	
		System.out.println("Reversed Linked List: ");
		printList(head);
	
	}
}
