import time
import sample
import unittest


class MyTestCase(unittest.TestCase):
    sampler = sample.Sample()

    def test_is_measuring(self):
        result = self.sampler.communicate("is_measuring")
        self.assertEqual(result.measuring, False)

    def test_simple_measure(self):
        self.sampler.set_sampler(sampler_name="mock_sampler")

        mock_tau = 100
        self.sampler.communicate("set_mock_tau {}".format(mock_tau))

        self.sampler.measure(number_of_waveforms=2, emitting_frequency=200)

        while self.sampler.is_measuring:
            time.sleep(0.1)

        result = self.sampler.query()
        self.assertEqual(result.success, True)

        self.assertTrue(0 < len(result.average) <= 1000)
        self.assertTrue(2.3 < result.average[0] < 2.7)


if __name__ == '__main__':
    unittest.main()
