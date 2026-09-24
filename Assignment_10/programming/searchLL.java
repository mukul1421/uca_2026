import java.util.*;

public class SearchLL {
	static class ListNode {
		int data;
		ListNode next;

		ListNode(int data) {
			this.data = data;
			this.next = null;
		}
	}

	static boolean search(ListNode head1, ListNode head2) {

		if(head1 == null)
			return true;

		while(head2 != null){

			ListNode temp1 = head1;
			ListNode temp2 = head2;

			while(temp1 != null && temp2 != null && temp1.data == temp2.data){
				temp1 = temp1.next;
				temp2 = temp2.next;
			}

			if(temp1 == null)
				return true;

			head2 = head2.next;
		}
		return false;
	}

	public static void main(String[] args) {

		ListNode head1 = new ListNode(1);
		head1.next = new ListNode(2);

		ListNode head2 = new ListNode(1);
		head2.next = new ListNode(3);
		head2.next.next = new ListNode(1);
		head2.next.next.next = new ListNode(3);
		head2.next.next.next.next = new ListNode(3);
		head2.next.next.next.next.next = new ListNode(4);


		boolean result = search(head1, head2);

		System.out.println(result);

	}
}

