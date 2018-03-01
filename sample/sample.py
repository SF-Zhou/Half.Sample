import st
import os
import subprocess
from . import Result


class Sample:
    @property
    def execution_path(self) -> str:
        main_path = os.path.join(os.path.dirname(__file__), '..')

        # build if SConstruct file exists
        if os.path.exists(os.path.join(main_path, 'SConstruct')):
            if os.system('cd {} && scons'.format(main_path)) != 0:
                raise self.Error("Compile C++ Driver Error")

        execution_name = 'sample.exe'
        if not os.path.exists(execution_name):
            execution_name = os.path.join(main_path, 'build', execution_name)
        if not os.path.exists(execution_name):
            print(execution_name)
            raise self.Error('Sample Driver Not Found')

        return execution_name

    @property
    def p(self) -> st.Process:
        p = getattr(self, 'p_', None)
        if p is not None:
            return p

        p = st.Process(self.execution_path)
        setattr(self, 'p_', p)
        return p

    def communicate(self, command: str, executor: st.Process=None) -> Result:
        executor = executor or self.p

        executor.write_line(command)
        lines = executor.read_until('EOF')

        result = Result()
        exec(lines, result.__dict__)

        if result.error:
            raise self.Error(result.message)

        return result

    @property
    def is_measuring(self) -> bool:
        return self.communicate('is_measuring').measuring

    def measure(self, number_of_waveforms: int, emitting_frequency: float) -> None:
        self.communicate("to_measure {} {:.2f}".format(number_of_waveforms, emitting_frequency))

    def set_sampler(self, sampler_name: str):
        self.communicate("set_sampler {}".format(sampler_name))

    def query(self) -> Result:
        result = self.communicate("to_query")
        result.process()
        return result

    class Error(EnvironmentError):
        pass
