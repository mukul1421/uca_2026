import java.util.*;

public class IntersectionLL {
	static class ListNode {
		int data;
		ListNode next;

		ListNode(int data) {
			this.data = data;
			this.next = null;
		}
	}

	static ListNode intersection(ListNode head1, ListNode head2) {

		ListNode resultHead = null;
		ListNode resultTail = null;

		while(head1 != null && head2 != null) {

			if(head1.data == head2.data){

				ListNode newNode = new ListNode(head1.data);
				if(resultHead == null){
					resultHead = newNode;
					resultTail = newNode;
				}
				else{
					resultTail.next = newNode;
					resultTail = resultTail.next;
				}

				head1 = head1.next;
				head2 = head2.next;
			}
			else if(head1.data < head2.data)
				head1 = head1.next;
			else
				head2 = head2.next;

		}

		return resultHead;

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

		ListNode head1 = new ListNode(1);
		head1.next = new ListNode(2);
		head1.next.next = new ListNode(2);
		head1.next.next.next = new ListNode(3);
		head1.next.next.next.next = new ListNode(4);

		ListNode head2 = new ListNode(2);
		head2.next = new ListNode(2);
		head2.next.next = new ListNode(2);
		head2.next.next.next = new ListNode(4);

		System.out.println("Original Linked List: ");
		printList(head1);
		printList(head2);

		ListNode result = intersection(head1, head2);

		System.out.println("Intersected Linked List: ");
		printList(result);

	}
}
