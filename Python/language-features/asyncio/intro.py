# Asynchronous programming is a single-threaded, single-process design.
# Coroutines that in the heart of asynchronous programming are can be 
# scheduled concurrently but they are not inherently concurrent. It 
# uses  cooperative multitasking which means program event loop 
# communicates with multiple tasks and when a task is waiting for 
# something to happen it schedules another task to execute them 
# optimally. 

# Coroutines are building blocks of asynchronous programming. They
# are specialized version of generators which is able to suspend its
# execution and pass control to another coroutine for some time. 

# A simple example:
import asyncio 

# async keyword makes this function a coroutine
async def count():
    # We shouldn't use time.sleep because it's a blocking function
    # We need a non-blocking function to pass control to other task
    print('One')
    # await keyword suspends the execution of the coroutine and passes
    # control back to the event loop. To use await with a function it
    # must be awaitable which means either another coroutine or object
    # that implements __await__() dunder method that returns an iterator.
    await asyncio.sleep(1)
    print('Two')

async def main():
    await asyncio.gather(count(), count(), count())

if __name__ == '__main__':
    asyncio.run(main)