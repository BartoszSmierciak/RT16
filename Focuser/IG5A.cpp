IG5A::IG5A()
{
//constructor    
}

int IG5A::GetFrequencyCommand()
{
    return _frequencyCommand;
}
    
void IG5A::SetFrequencyCommand(int frequencyCommand)
{
    if(frequencyCommand >=0 && frequencyCommand<=400 )
        _frequencyCommand = frequencyCommand;
    else
        _frequencyCommand = 0;
        
}
