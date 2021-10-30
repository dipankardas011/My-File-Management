# Creating the File management

simple one

* each nodes contains a max size of nodes that it can have example 11 items inside one directory
* root contains only node and others are NULL
eg

```graph
        root nill nill nill nill..11
        / / / /...\ \ \
       /  .. ...  ........
      /
    child1 child2 child3 ... child10
```

## to run the container
```bash
docker build buildenv -t "name-of-image"
```
to run the contaniner
```ps
docker run --rm -it -v "${pwd}:/root/env" "name-of-image" 
```
## Cleanup

Remove the build-evironment image:
```ps
docker rmi "name-of-image" -f
```