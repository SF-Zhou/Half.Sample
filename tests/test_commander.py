import unittest
from sample import sampler


class MyTestCase(unittest.TestCase):
    def test_commander_frame(self):
        result = sampler.communicate("simple_test")
        self.assertTrue(result.success)

        try:
            result = sampler.communicate("unknown_command")
        except sampler.Error as e:
            self.assertTrue(str(e).startswith("command_not_found"))


if __name__ == '__main__':
    unittest.main()
