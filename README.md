# The philosophers problem
The classic dining philosopher problem.

This problem states that N philosophers seated around a circular table with one fork between each pair of philosophers. A philosopher may eat if he can pick up the two forks adjacent to him. One fork may be picked up by any one of its adjacent followers but not both.

<div align="center">
  <img width=300px height=300px src="https://upload.wikimedia.org/wikipedia/commons/7/7b/An_illustration_of_the_dining_philosophers_problem.png" />
</div>


Each time a philosopher finish eating, they will drop drop their forks and start sleeping. Once they have finished sleeping, the will start thinking and waiting to eat.

Simulation stops when a philosopher dies.

Every philosopher needs to eat and they should never starve.

Philosophers do not speak with each other.

Philosophers do not know when another philospher is about to die.

And of course, philosophers should avoid dying.

## How to use

Clone the repo

```sh
git clone https://github.com/izenynn/Phlisophers.git
```
Go to `philo` or `philo_bonus` folder and run `make`

```sh
cd ./philo && make
```
- *Makefile rules: `all`, `clean`, `fclean`, `re`).*

Usage

```sh
./philo [N PHILOS] [DIE TIME] [EAT TIME] [SLEEP TIME] (OPT)[PHILO EAT N TIMES]
```

- last argument is optional.

- `philo_bonus` takes the same arguments as `philo`.

Example

```sh
./philo 4 800 200 200
```
<img src="https://github.com/csalihburak/Philosophers/blob/master/images/image.png" />
