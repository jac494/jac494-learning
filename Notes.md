


```c
void bar(int a, int b) {
    int x, y;
    x = 555;
    y = a+b;
}

void foo(void) {
    bar(111, 222);
}

int main() {foo(); }
```

Assembly for the C code above: (command for this is `gcc -S -m32 Source.c`)

```
bar:        # ---------------------------- start of the function bar()
	pushl	%ebp                           # save the incoming frame pointer
	movl	%esp, %ebp                     # set the frame pointer to the current top of the stack
	subl	$16, %esp                      # increase the stack by 16 bytes (stack grows down)
	call	__x86.get_pc_thunk.ax          # no idea
	addl	$_GLOBAL_OFFSET_TABLE_, %eax   # no idea
	movl	$555, -8(%ebp)                 # x=555 is located at [ebp-8]
	movl	8(%ebp), %edx                  # 8(%ebp) is [ebp+8], which is the first param, store in edx
	movl	12(%ebp), %eax                 # 12(%ebp) is [ebp+12], which is the first param, store in eax
	addl	%edx, %eax                     # add them
	movl	%eax, -4(%ebp)                 # store the result in y
	nop
	leave
	ret
foo:        # ---------------------------- start of the function foo()
	pushl	%ebp                           # save the current frame pointer
	movl	%esp, %ebp                     # set the frame pointer to the top of the current stack
	call	__x86.get_pc_thunk.ax          # no idea
	addl	$_GLOBAL_OFFSET_TABLE_, %eax   # no idea
	pushl	$222                           # this is effectively pushing 222 on the stack
	pushl	$111                           # this is effectively pushing 111 on the stack
	call	bar                            # call = push the instruction pointer on the stack and branch to bar
	addl	$8, %esp                       # increase the stack by 8 bytes
	nop
	leave
	ret
main:
	endbr32  # this was in all of them but I deleted it; "end branch 32" ~ essentially a NOP
	pushl	%ebp                           # save the current frame pointer
	movl	%esp, %ebp                     # set the frame pointer to the top of the current stack
	call	__x86.get_pc_thunk.ax          # no idea
	addl	$_GLOBAL_OFFSET_TABLE_, %eax   # no idea
	call	foo                            # call = push the instruction pointer on the stack and branch to bar
	movl	$0, %eax                       # (guessing on this one) set eax to zero?
	popl	%ebp                           # (guessing on this one, too) pop current frame pointer off base pointer register?
	ret

```
