class AVLTree {
	class Node {
		int key, height;
		Node left, right;

		Node(int d) {
			key = d;
			height = 1;
		}
	}
	private Node root;

	private int height(Node N) {
		if(N == null) {
			return 0;
		}
		return N.height;
	}

	private Node rRotate(Node y) {
		Node x = y.left;
		Node z = y.right;

		x.right = y;
		y.left = z;

		y.height = Math.max(height(y.left), height(y.right)) + 1;
		x.height = Math.max(height(x.left), height(x.right)) + 1;

		return x;
	}
	private Node lRotate(Node x) {
		Node y = x.right;
		Node z = y.left;

		y.left = x;
		x.right = z;

		x.height = Math.max(height(x.left), height(x.right)) + 1;
		y.height = Math.max(height(y.left), height(y.right)) + 1;

		return y;
	}
	private int getBalance(Node N) {
		if(N == null) {
			return 0;
		}
		return height(N.left) - height(N.right);
	}
	public void insert(int key) {
		root = insert(root, key);
	}
	private Node insert(Node n, int key) {
		if(n == null) {
			return new Node(key);
		}
		if(key < n.key) {
			n.left = insert(n.left, key);
		} else if(key > n.key) {
			n.right = insert(n.right, key);
		} else {
			return n;
		}
		n.height = 1 + Math.max(height(n.left), height(n.right));

		int balance = getBalance(n);

		if(balance > 1 && key < n.left.key) {
			return rRotate(n);
		}
		if(balance < -1 && key > n.right.key) {
			return lRotate(n);
		}
		if(balance > 1 && key > n.left.key) {
			n.left = lRotate(n.left);
			return rRotate(n);
		}
		if(balance < -1 && key < n.right.key) {
			n.right = rRotate(n.right);
			return n;
		}
		return n;
	}
	public void inOrder() {
		inOrder(root);
	}
	private void inOrder(Node n) {
		if(n != null) {
			inOrder(n.left);
			System.out.print(n.key + " ");
			inOrder(n.right);
		}
	}
	public static void main(String []args) {
		AVLTree tree = new AVLTree();
		tree.insert(10);
		tree.insert(20);
		tree.insert(30);
		tree.insert(40);
		tree.insert(50);
		tree.insert(25);
		System.out.println("Inorder traversal of the AVL tree is: ");
		tree.inOrder();
	}
}
