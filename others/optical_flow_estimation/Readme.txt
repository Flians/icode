Preparation
a) download data from given link and put them under the `data/' and `open_challenge/data' folders (you can use `ln -s' to create a soft link the data)
b) python requirements
   - numpy
   - PyTorch (> 1.0)
   - scipy
   - scikit-image
   - tensorboardX
   - colorama, tqdm, setproctitle

Task1: Implement FlowNet Encoder
a) Implement `networks/FlowNetE.py'

Task2: Loss Function
a) Implement `EPELoss' in `losses.py'
b) run `run_E.sh'

Task3: Refinement Module
a) Implement `networks/FlowNetER.py'
b) run `run_ER.sh'

Task4: Multi-scale Optimization
a) Implement `networks/FlowNetERM.py'
b) Implement `MultiscaleLoss' in `losses.py'
c) run `run_ERM.sh'

Task5: Open Challenge
a) go into the `open_challenge' directory, implement 'networks/FlowNetOurs.py' and 'Oursloss' in 'losses.py'
b) you can also modify input transformation code in 'dataset.py'
c) run `run_ours.sh'


Notation
a) the best validation EPE is printed in the log.
b) FLOPs and params are printed in the log.
c) `test_*.sh' is used to evalute the trained model

Submission
a) you need to sumbit the codes and trained checkpoints (save in `work/' automatically)
b) you should only keep `*_model_best.pth.tar' and clean other irrelevant files in `work/'
c) you should move `data/' out before `zip'
d) add a readme file to tell the TAs which tasks you complete.

