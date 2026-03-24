# peer_review_self_check.md

> This file is a helper I created for Task 3.  
> The original task does **not** require a specific file, but this checklist makes the review criteria concrete.

## Memory model

- [ ] I clearly separate stack objects from heap objects
- [ ] I explain exactly when each important object stops being valid
- [ ] I never imply that stack memory survives function return
- [ ] I state who owns each heap allocation and who must free it

## Pointer reasoning

- [ ] I explain when two pointers alias the same object
- [ ] I identify dangling pointers explicitly
- [ ] I explain use-after-free as a lifetime violation, not as “weird behaviour”
- [ ] I distinguish between printing a pointer value and dereferencing it

## Valgrind reasoning

- [ ] I classify each warning correctly
- [ ] I connect each warning to a specific line of code
- [ ] I explain *why* the memory misuse happens
- [ ] I do not paste Valgrind output without interpretation

## Crash reasoning

- [ ] I explain the exact invalid access that causes the crash
- [ ] I describe the full chain from code to fault
- [ ] I label the bug precisely (for example: null pointer dereference)
- [ ] I avoid circular wording such as “it crashes because of a segfault”

## AI critique

- [ ] I say how AI was used
- [ ] I include at least one AI mistake, omission, or misleading claim
- [ ] I explain why that AI explanation was wrong
- [ ] I treat AI as a draft, not as authority

## Final test

If another student reads my files for 20 minutes, can they see my understanding **without asking me questions**?

- [ ] Yes
